<?php
/**
 * Created by PhpStorm.
 * User: ECHUANG
 * Date: 2015/7/31
 * Time: 10:45
 */
class wxModel extends model{
    private $appId;
    private $appSecret;
    private $access_token;

    public function __construct(){
        parent::__construct();
        self::getAppInfo();
    }
    public function index(){
        echo "wxModel";
    }

    public function test(){

        print_r($this->httpGet("www.yaopiaoma.com"));

        $sql = "select * from t_test";
        $stmt = $this->dbh->query($sql);
        return $stmt->fetchAll();
    }
    /**
     * 从./wxpublic/appInfo.json获取appId、appSecret
     *  {"appId":"appId","appSecret":"appSecret"}
     */
    private function getAppInfo(){
        $data = json_decode(file_get_contents('./wxpublic/appInfo.json'));
        if(!empty($data)){
            $this->appId = $data->appId;
            $this->appSecret = $data->appSecret;
        }else{
            echo "appId、appSecret不存在或错误!";
        }
    }
    /**
     * 获取ACCESS_TOKEN数据并写入到./wxpublic/access_token.json文件
     *
     * @return $access_token
     *
     */
    public function fetchAccessToken(){
        $data = json_decode(file_get_contents('./wxpublic/access_token.json'));
        if($data->expires_in < time()){
            //企业URL
            //$url = "https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=$this->appId&corpsecret=$this->appSecret";
            $url = "https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=$this->appId&secret=$this->appSecret";
            //curl方式解析url地址返回数据并json转换
            $res = json_decode($this->httpGet($url));
            $access_token = $res->access_token;
            if(!empty($access_token)){
                $data->expires_in = time() + 7200;
                $data->access_token = $access_token;
                $fp = fopen('./wxpublic/access_token.json','w');
                fwrite($fp,json_encode($data));
                fclose($fp);
            }
        }else{
            $access_token = $data->access_token;
        }
        $this->access_token = $access_token;
        return $access_token;
    }
    /**
     * 获取ACCESS_TOKEN的JSON数据
     */
    private function httpGet($url){
        $curl = curl_init();
        curl_setopt($curl,CURLOPT_RETURNTRANSFER,true);
        curl_setopt($curl,CURLOPT_TIMEOUT,500);
        curl_setopt($curl,CURLOPT_SSL_VERIFYPEER,false);
        curl_setopt($curl,CURLOPT_SSL_VERIFYHOST,false);
        curl_setopt($curl,CURLOPT_URL,$url);
        $res = curl_exec($curl);
        curl_close($curl);
        return $res;
    }
    /**
     * 获取微信服务器的ip地址
     * @return array $ips 数组形式返回ip地址列表
     *
     * now => json
     *
     */
    public function getWxServIp(){
        $url = "https://api.weixin.qq.com/cgi-bin/getcallbackip?access_token=$this->access_token";
        return json_decode(self::httpGet($url))->ip_list;
    }
    /**
     * 重新获取access_token
     */
    public function reGetAccessToken(){
        $data = (object)null;
        $data->access_token = $this->access_token;
        $data->expires_in = 0;
        $fp = fopen('./wxpublic/access_token.json','w');
        fwrite($fp,json_encode($data));
        fclose($fp);
        self::fetchAccessToken();
    }
    /*************微信小店接口 Begin Auth WJK****************/
    /**
     * 获取所有货架接口
     * @return array $shelves 货架的信息数组
     * now => json
     */
    public function getAllShelves(){
        $url = "https://api.weixin.qq.com/merchant/shelf/getall?access_token=$this->access_token";
        return json_decode(self::httpGet($url));
    }
    /**
     * 上传图片接口
     *
     */
    public function uploadImg(){
        $url = "https://api.weixin.qq.com/merchant/common/upload_img?access_token=$this->access_token&filename=test.png";
    }
    /*************微信小店接口 End Auth WJK****************/



}
?>
