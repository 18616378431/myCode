<?php
/**
 * Created by PhpStorm.
 * User: akily
 * Date: 16/5/22
 * Time: 下午3:11
 */
namespace Wx\Model;
use Think\Model;

class TokenModel extends Model{
    //  AppID:wxc791d0212281c778
    //  AppSecret:c4d99c60b3206b6d8b31edf1872094ff
    //  http请求方式: GET
    //  private $url = "https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=APPID&secret=APPSECRET";
    //  https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=wxc791d0212281c778&secret=c4d99c60b3206b6d8b31edf1872094ff
    private $appid;
    private $appsecret;
    private $requestUrl;
    private $accessTokenUrl;//获取access_token持有对象
    public $access_token;//持有获取到的access_token
    private $serverIpUrl;//服务器IP URL持有对象
    private $createCustomMenuUrl;//自定义菜单创建接口URL持有对象
    private $getCustomMenuUrl;//查询自定义菜单接口URL持有对象


    //架构函数,对该模块所需数据进行初始化
    public function __construct()
    {
        parent::__construct();
        $this->appid = 'wxc791d0212281c778';
        $this->appsecret = 'c4d99c60b3206b6d8b31edf1872094ff';
        $this->accessTokenUrl = "https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid=$this->appid&secret=$this->appsecret";
        //为持有对象获取access_token
        $this->fetchAccessToken();
    }
    //将获取到的access_token存储到数据库,参数$access_token,$expires_in
    public function dbToken($access_token,$expires_in){
        $rs = $this->getAccessTokenIdFromDb();
        $this->id = $rs['id'] + 1;
        $this->access_tokendb = $access_token;
        $this->expires_in = $expires_in;
        $this->get_time = time();
        $this->client_ip = get_client_ip();
        $this->dates = date('Y-m-d H:i:s');
        $this->add();
    }
    //获取access_token
    public function fetchAccessToken(){
        if(!($res = $this->isExpiresIn())){//超时,重新获取,并向数据库插入新的一条access_token信息
            $access_obj = $this->httpGet($this->accessTokenUrl);
            $this->access_token = $access_obj->access_token;
            //写入
            $this->dbToken($access_obj->access_token,$access_obj->expires_in);
        }else{//未超时
            $this->access_token = $res['access_tokendb'];
        }
    }
    //检测当前access_token是否超时,超时返回false,未超时返回true
    public function isExpiresIn(){
        $new = $this->getAccessTokenFromDb();
        if(time() > ($new['get_time'] + 7200)){//超时,或不存在,重新获取
            return false;
        }else{//未超时
            return $new;
        }
    }
    //根据url获取信息,返回php对象,第二个参数为请求发送方式,$postPrama POST请求参数
    public function httpGet($url,$requestType = '',$postParam = ''){
        $ch = curl_init();
        //curl参数设置
        curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);//返回存储到变量不直接输出
        curl_setopt($ch,CURLOPT_TIMEOUT,500);//超时时间
        curl_setopt($ch,CURLOPT_SSL_VERIFYPEER,false);
        curl_setopt($ch,CURLOPT_SSL_VERIFYHOST,false);

        if(!empty($requestType)){
            curl_setopt($ch,CURLOPT_CUSTOMREQUEST,$requestType);
            curl_setopt($ch,CURLOPT_POSTFIELDS,$postParam);
            curl_setopt($ch,CURLOPT_HTTPHEADER,array(
                'Content-Type:application/json',
                'Content-Length:'.strlen($postParam)
            ));
         }
        curl_setopt($ch,CURLOPT_URL,$url);
        $res = curl_exec($ch);//抓取url
        curl_close($ch);
        return json_decode($res);
    }
    //获取最新一条access_token
    public function getAccessTokenFromDb(){
        return $this->order('get_time desc')->limit(1)->find();
    }
    public function getAccessTokenIdFromDb(){
        return $this->order('id desc')->limit(1)->find();
    }

    //获取微信服务器ip
    //http请求方式:GET
    //https://api.weixin.qq.com/cgi-bin/getcallbackip?access_token=ACCESS_TOKEN
    //return array
    public function getServerIp(){
        //获取access_token后,拼接服务器IP地址url
        $this->serverIpUrl = "https://api.weixin.qq.com/cgi-bin/getcallbackip?access_token=$this->access_token";
        return $this->httpGet($this->serverIpUrl)->ip_list;
    }

    /** ########订阅号没有相关菜单自定义接口调用权限########## */
    //获取自定义菜单接口
    //http请求方式：POST（请使用https协议）
    // https://api.weixin.qq.com/cgi-bin/menu/create?access_token=ACCESS_TOKEN
    // https://api.weixin.qq.com/cgi-bin/menu/create?access_token=ACCESS_TOKEN
    public function createCustomMenu(){
        $this->createCustomMenuUrl = "https://api.weixin.qq.com/cgi-bin/menu/create?access_token=$this->access_token";
        $xjson = '';
        return $this->httpGet($this->createCustomMenuUrl,'POST',$xjson);
    }
    //自定义菜单查询接口
    //http请求方式：GET
    //https://api.weixin.qq.com/cgi-bin/menu/get?access_token=ACCESS_TOKEN
    public function getCustomMenu(){
        $this->getCustomMenuUrl = "https://api.weixin.qq.com/cgi-bin/menu/get?access_token=$this->access_token";
        return $this->httpGet($this->getCustomMenuUrl);
    }
    /** ########订阅号没有相关菜单自定义接口调用权限########## */
}