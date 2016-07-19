<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2016/7/12
 * Time: 17:21
 */
namespace WxExt\Wx;
use Think\Model;
class JSSDK {
    private $appId;
    private $appSecret;

    private $wxModel;
    private $token_info;
    private $ticket_info;

    public function __construct($appId, $appSecret) {
        $this->appId = $appId;
        $this->appSecret = $appSecret;
        $this->set_model('wx_autho');
        $this->get_token_ticket();
    }

    public function getSignPackage() {
        $jsapiTicket = $this->getJsApiTicket();

        // 注意 URL 一定要动态获取，不能 hardcode.
        $protocol = (!empty($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off' || $_SERVER['SERVER_PORT'] == 443) ? "https://" : "http://";
        $url = "$protocol$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]";

        $timestamp = time();
        $nonceStr = $this->createNonceStr();

        // 这里参数的顺序要按照 key 值 ASCII 码升序排序
        $string = "jsapi_ticket=$jsapiTicket&noncestr=$nonceStr&timestamp=$timestamp&url=$url";

        $signature = sha1($string);

        $signPackage = array(
            "appId"     => $this->appId,
            "nonceStr"  => $nonceStr,
            "timestamp" => $timestamp,
            "url"       => $url,
            "signature" => $signature,
            "rawString" => $string
        );
        return $signPackage;
    }

    private function createNonceStr($length = 16) {
        $chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        $str = "";
        for ($i = 0; $i < $length; $i++) {
            $str .= substr($chars, mt_rand(0, strlen($chars) - 1), 1);
        }
        return $str;
    }

    private function getJsApiTicket() {
        // jsapi_ticket 应该全局存储与更新，以下代码以写入到文件中做示例
//        $data = json_decode($this->get_php_file("jsapi_ticket.php"));
        $data = json_decode($this->ticket_info);
        if ($data->expire_time < time()) {
            $accessToken = $this->getAccessToken();
            // 如果是企业号用以下 URL 获取 ticket
            // $url = "https://qyapi.weixin.qq.com/cgi-bin/get_jsapi_ticket?access_token=$accessToken";
            $url = "https://api.weixin.qq.com/cgi-bin/ticket/getticket?type=jsapi&access_token=$accessToken";
            $res = json_decode($this->httpGet($url));
            $ticket = $res->ticket;
            if ($ticket) {
                $data->expire_time = time() + 7000;
                $data->jsapi_ticket = $ticket;
//                $this->set_php_file("jsapi_ticket.php", json_encode($data));
                $this->set_token_ticket("jsapi_ticket", json_encode($data));
            }
        } else {
            $ticket = $data->jsapi_ticket;
        }

        return $ticket;
    }

    private function getAccessToken() {
//    public function getAccessToken() {
        // access_token 应该全局存储与更新，以下代码以写入到文件中做示例
//        $data = json_decode($this->get_php_file("access_token.php"));
        $data = json_decode($this->token_info);
        if ($data->expire_time < time()) {
            // 如果是企业号用以下URL获取access_token
            // $url = "https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=$this->appId&corpsecret=$this->appSecret";
            $url = "https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=$this->appId&secret=$this->appSecret";
            $res = json_decode($this->httpGet($url));
            $access_token = $res->access_token;
            if ($access_token) {
                $data->expire_time = time() + 7000;
                $data->access_token = $access_token;
//                $this->set_php_file("access_token.php", json_encode($data));
                $this->set_token_ticket("access_token", json_encode($data));
            }
        } else {
            $access_token = $data->access_token;
        }
        return $access_token;
    }

    private function httpGet($url) {
        $curl = curl_init();
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curl, CURLOPT_TIMEOUT, 500);
        // 为保证第三方服务器与微信服务器之间数据传输的安全性，所有微信接口采用https方式调用，必须使用下面2行代码打开ssl安全校验。
        // 如果在部署过程中代码在此处验证失败，请到 http://curl.haxx.se/ca/cacert.pem 下载新的证书判别文件。
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, false);
        curl_setopt($curl, CURLOPT_URL, $url);
        $res = curl_exec($curl);
        curl_close($curl);
        return $res;
    }

    private function get_php_file($filename) {
        return trim(substr(file_get_contents($filename), 15));
//        return trim(substr($this->token_info, 15));
//        new \Think\Model();
    }
    private function set_php_file($filename, $content) {
        $fp = fopen($filename, "w");
        fwrite($fp, "<?php exit();?>" . $content);
        fclose($fp);
    }

    /**
     * 封装access_token和jsapi_ticket数据库操作
     */
    private function set_model($table_name){
        $this->wxModel = new Model($table_name);
    }
    /**
     * 获取token和ticket
     */
    private function get_token_ticket(){
//        $m = new Model('Wx_autho');
//        $rs = $m->field("*")->table('wx_autho')->order('id desc')->find();
        $rs = $this->wxModel->order('id desc')->find();
        if(empty($rs)){
            $data['access_token'] = '<?php exit();?>{"access_token":"","expire_time":0}';
            $data['jsapi_ticket'] = '<?php exit();?>{"jsapi_ticket":"","expire_time":0}';
            $newId = $this->wxModel->add($data);
        }
        $rs = $this->wxModel->order('id desc')->find($newId);

        $this->token_info = $rs['access_token'];
        $this->ticket_info = $rs['jsapi_ticket'];
    }
    /**
     * 设置token和ticket
     */
    private function set_token_ticket($field,$value){
        $data["$field"] = $value;
        $this->wxModel->where(1)->save($data);
    }

}
//授权数据库
/*
Navicat MySQL Data Transfer

Source Server         : UbuntuMysql
Source Server Version : 50712
Source Host           : 192.168.1.118:3306
Source Database       : taojin

Target Server Type    : MYSQL
Target Server Version : 50712
File Encoding         : 65001

Date: 2016-07-18 12:03:00
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `wx_autho`
-- ----------------------------
DROP TABLE IF EXISTS `wx_autho`;
CREATE TABLE `wx_autho` (
  `id` int(4) unsigned NOT NULL AUTO_INCREMENT,
  `access_token` varchar(300) DEFAULT NULL,
  `jsapi_ticket` varchar(300) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of wx_autho
-- ----------------------------
INSERT INTO `wx_autho` VALUES ('4', '{\"expire_time\":1468660974,\"access_token\":\"ukx1hV-xiuVfVslNPx-whtHouN6AiZMzAkOEjJ65s02pMWbt-_ROEMO1gSXBtrjE6w9VvvqWC48VTGLJ47uFXhXhU7y0Mde9_KSjy_mVtLKf6kHuOnnnXdjCjnE-57IpHUFbAAABOZ\"}', '{\"expire_time\":1468660974,\"jsapi_ticket\":\"kgt8ON7yVITDhtdwci0qebnDqqzzFTM_mHn9E3M_E7WKP61-2f08kojUHlynkx7K-pLZDrVwiiN8bs88nK8E9g\"}');
