<?php
/**
 * Created by PhpStorm.
 * User: ECHUANG
 * Date: 2015/7/31
 * Time: 10:45
 */
/**
 * Class wxModel
 * 企业号
 * {"appId":"wx6adcfcc89768279a","appSecret":"3de6ef40953079c7309066635da12aae "}
 *
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
//        self::addIntoDb(self::mergeArray());
//        $obj = self::getRssAddrFromDb();
//        var_dump($obj);
        echo "wxModel";
    }
    public function test(){
//        print_r($this->httpGet("www.yaopiaoma.com"));
//        $sql = "select * from t_test";
//        $stmt = $this->dbh->query($sql);
//        echo str_replace("'","\"","sdflg'hsldkf'ghasdf'ada'sa'da");
//        return $stmt->fetchAll();
        echo substr("/account/sagacity-mac/feed/",0,8);
        var_dump(strcmp(substr("/account/sagacity-mac/feed/",0,8),"/account") == 0);
    }
    /**
     * 从./wxpublic/appInfo.json获取appId、appSecret
     *  {"appId":"appId","appSecret":"appSecret"}
     */
    private function getAppInfo(){
        $data = json_decode(file_get_contents('./wxpublic/appInfo1.json'));
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
        $curl = curl_init();//初始化cUrl，返回curl句柄
        curl_setopt($curl,CURLOPT_RETURNTRANSFER,true);//以文件流的形式返回
        curl_setopt($curl,CURLOPT_TIMEOUT,500);//超时时间
        curl_setopt($curl,CURLOPT_SSL_VERIFYPEER,false);//服务器端验证
        curl_setopt($curl,CURLOPT_SSL_VERIFYHOST,false);
        curl_setopt($curl,CURLOPT_URL,$url);//要获取的URL地址
        $res = curl_exec($curl);//抓取URL
        curl_close($curl);//关闭cUrl资源并释放系统资源
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
    /**
     * 自定义菜单查询接口
     *
     */
    public function customMenu(){
        $url = "https://api.weixin.qq.com/cgi-bin/menu/get?access_token=$this->access_token";
        $res = json_decode(self::httpGet($url));
        return $res;
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
    /**
     * 获取素材总数
     *
     */
    public function getMaterial(){
        $url = "https://api.weixin.qq.com/cgi-bin/material/batchget_material?access_token=$this->access_token";
        $res = json_decode(self::httpGet($url));
        return $res;
    }
    /*************微信小店接口 End Auth WJK****************/
    /*************微信RSS源 Begin Auth WJK****************/
    /**
     * 调试RSS
     * @param string $url 源地址
     */
    public function rssDebug($url){
        $xml = file_get_contents($url);
        $p = xml_parser_create();
        xml_parser_set_option($p,XML_OPTION_SKIP_WHITE,1);
        xml_parse_into_struct($p,$xml,$values,$idx);
        xml_parser_free($p);
        var_dump($values);
    }
    /**
     * 检测RSS地址是否为weirss
     * @param string $url 源地址
     */
    public function rssIsRight($url){
        $xml = @file_get_contents($url);
        $p = xml_parser_create();
        xml_parser_set_option($p,XML_OPTION_SKIP_WHITE,1);
        xml_parse_into_struct($p,$xml,$values,$idx);
        xml_parser_free($p);
        if(!empty($values)){
            return true;
        }
        return false;
    }
    /**
     * 返回数组、数组元素为对象
     * @return mixed
     */
    private function getRssAddrFromDb(){
        $sql = "select * from t_rssurl";
        $stmt = $this->dbh->query($sql);
        $arr = $stmt->fetchAll();
        for($i = 0;$i < count($arr);$i++){
            $newArr[$i] = $arr[$i]->url;
        }
//        var_dump($newArr);
        return $newArr;
    }
    /**
     * 从数据库获取全部rss地址、获取文章内容、写入数据库
     *
     * 遍历rss地址数组、将当前最热weirss全部写入数据库
     * MacTalk:http://weirss.me/account/sagacity-mac/feed/
     * 商业周刊中文版:http://weirss.me/account/businessweek/feed/
     * 媒体札记:http://weirss.me/account/xdnmtzj/feed/
     * 高可用架构:http://weirss.me/account/gh_ef1c37a72e61/feed/
     * 千喜来客:http://weirss.me/account/gh_7b58526fbbe6/feed/
     *
     *
     *
     */
    public function weiRssAll(){
        $weirssArr = self::getRssAddrFromDb();
        for($i = 0;$i < count($weirssArr);$i++){
//            $this->wx->getRss("http://weirss.me/account/xiutuxi/feed/",9,8,3,1,2,3,4);
            self::getRss($weirssArr[$i],9,8,3,1,2,3,4);
//            self::rssDebug($weirssArr[$i]);
//            echo $weirssArr[$i];
        }
    }
    /**
     * 微信RSS源
     * @param string $url 源地址
     * @param int $iBegin 遍历开始位置
     * @param int $step 步长
     * @param int $distance DESCRIPTION距离title的距离
     *
     * @param int $linkToTitle link距离title的距离
     * @param int $auToTitle author距离title的距离
     * @param int $cToTitle content距离title的距离
     * @param int $pToTitle publishdate距离title的距离
     *
     * @return null
     */
    public function getRss($url,$iBegin,$step,$distance,$linkToTitle,$auToTitle,$cToTitle,$pToTitle){
        //$url = "http://weirss.me/account/xiutuxi/feed/";
        $xml = file_get_contents($url);
        $p = xml_parser_create();
        xml_parser_set_option($p,XML_OPTION_SKIP_WHITE,1);
        xml_parse_into_struct($p,$xml,$values,$idx);
        xml_parser_free($p);
        for($i = $iBegin,$index = 0;$i < count($values);$i += $step,$index++){
            if(empty($values[$i + $distance]['value'])){
                continue;
            }else{
                $data[$index]['title'] = $values[$i]['value'];
                $data[$index]['link'] = $values[$i + $linkToTitle]['value'];
                $data[$index]['author'] = $values[$i + $auToTitle]['value'];
                $data[$index]['content'] = $values[$i + $cToTitle]['value'];
                $data[$index]['publishdate'] = date('Y-m-d H:i:m',strtotime($values[$i + $pToTitle]['value']));
                $data[$index]['verify'] = substr(md5($values[$i]['value']),8,16);
            }
        }
//        var_dump($data);
        if(!empty($data)){
            self::addAll($data);
        }
    }
    /**
     * 遍历二维数组并全部写入数据库
     * @param array $data
     */
    private function addAll($data){
        foreach($data as $d){
            //$this->dbh->insert('t_wxrss')->data($d)->exec();
            if(self::isConExists($verify = $d['verify'])){
                continue;
            }else{
                $title = $d['title'];
                $link = $d['link'];
                $author = $d['author'];
                $content = self::replaceStr($d['content']);
                $publishdate = $d['publishdate'];
                $sql = "insert into t_wxrss(title,link,author,content,publishdate,verify) VALUES ('".$title."','".$link."','".$author."','".$content."','".$publishdate."','".$verify."')";
                $this->dbh->exec($sql);
            }
        }
    }
    /**
     * @param $vertify
     */
    private function isConExists($vertify){
        $sql = "select verify from t_wxrss where verify='".$vertify."'";
        $stmt = $this->dbh->query($sql);
        $rs = $stmt->fetch();
        if($rs){
            return true;
        }
        return false;
    }
    /**
     * @param $str
     */
    private function  replaceStr($str)
    {
        return str_replace("'", "\"", $str);
    }
    /**
     * 获取页面内容,获取页面中的全部http://weirss.me/account开头的url地址
     */
    public function getPageContent($url){
        $html = file_get_contents($url);
        $dom = new DOMDocument();//实例化DOM对象
        @$dom->loadHTML($html);
        $xpath = new DOMXPath($dom);
        $hrefs = $xpath->evaluate('/html/body//a');
        $urls = array();
        for($i = 0;$i < $hrefs->length;$i++){
//        for($i = 0;$i <= 20;$i++){
            $href = $hrefs->item($i);
            $url = $href->getAttribute('href');
//            if(substr($url,0,24) == 'http://weirss.me/account'){
                $urls[$i] = $url;
//            }
        }
//        var_dump($urls);
        return $urls;
    }
    /**
     * 获取一级url下的二级url页面
     * 全部rss源地址
     */
    public function getSecondPage(){
        $urls = self::getPageContent("http://weirss.me");
        for($i = 1;$i <= 20;$i++){
            $urlA = self::getPageContent($urls[$i]);
            if(!empty($urlA) && strcmp(substr($urlA[0],0,8),"/account") == 0){
                ;
            }
            $arr[$i] = "http://weirss.me".$urlA[0];
        }
//        var_dump($arr);
        //self::getAllUrlName();
//        $str = "http://weirss.me".$urls[1];//ROOT
//        $urlsA = self::rssDebug("$str");
//        var_dump($urlsA);
        return $arr;
    }
    /**
     * 获取页面中的全部链接、正则过滤
     *
     */
    public function getAllUrlName(){
        $str = file_get_contents("http://weirss.me/");
        $pat = '/<a(.*?)href="(.*?)"(.*?)>(.*?)<\/a>/i';
        preg_match_all($pat, $str, $m);
        //var_dump($m[4]);
        for($i = 1;$i <= 20;$i++){
            $arr[$i] = $m[4][$i];
        }
        //var_dump($arr);
        return $arr;
    }
    /**
     * 将超链接和链接名称组合为二维数组、并写入数据库
     */
    private function mergeArray(){
        $href = self::getSecondPage();
        $urlName = self::getAllUrlName();
        $newArr = array_merge($href,$urlName);
//        $newArr = array_combine($urlName,$href);
//        var_dump($newArr);
//        var_dump($href);
//        var_dump($urlName);
        return $newArr;
    }
    /**
     * @param array $arr//将数组内容写入数据库
     * @return null
     */
    private function addIntoDb($arr){
        for($i = 0;$i < 20;$i++){
            if(self::isSubExist($arr[$i + 20])){
                continue;
            }else{
                $sql = "INSERT INTO t_rssurl(name,url) VALUES ('".$arr[$i + 20]."','".$arr[$i]."')";
                $this->dbh->exec($sql);
            }
        }
    }
    /**
     * 查询数据库中是否已经存在该RSS订阅
     * @param $subName
     * @return true|false
     */
    private function isSubExist($subName){
        $sql = "select name from t_rssurl where name='".$subName."'";
        $stmt = $this->dbh->query($sql);
        $rs = $stmt->fetch();
        if($rs){
            return true;
        }
            return false;
    }
    /**
     * 从页面内容中获取超链接
     * @param string $content
     * @return array $m
     */
    public function get_links($content){
            $pattern = '/<a(.*?)href="(.*?)"(.*?)>(.*?)<\/a>/i';
            preg_match_all($pattern, $content, $m);
            return $m;
    }
    /*************微信RSS源 End AUTH WJK****************/
    /**
     * 外部调用方法、获取文章内容
     * @param $category
     * @return mixed
     */
    public function getContent($category = ""){
        $sql = "select * from t_wxrss";
        if(!empty($category)){
            $sql = $sql." where author = '".$category."'";
        }
        $sql = $sql." order by publishdate desc";
        $stmt = $this->dbh->query($sql);
        $arr = $stmt->fetchAll();
//        var_dump($arr);
        return $arr;
    }
    /**
     * 外部调用方法、将最新rss地址写入数据库
     */
    public function addRssUrlToDb(){
        self::addIntoDb(self::mergeArray());
    }
    /**
     * 获取全部rss类别名称
     * @return array
     */
    public function getRssCategory(){
        $sql = "select name from t_rssurl";
        $stmt = $this->dbh->query($sql);
        return $stmt->fetchAll();
    }
    /**
     * 查询数据库中不正确的URL地址并删除地址
     * @return int
     */
    public function getIncorrectUrl(){
        $sql = "select * from t_rssurl";
        $stmt = $this->dbh->query($sql);
        $rs = $stmt->fetchAll();
        $count = 0;
        foreach($rs as $r){
            if(strcmp(substr($r->url,0,24),"http://weirss.me/account") != 0){
                self::delIncorrectUrl($r->id);
                $count++;
            }//http://weirss.me/account
        }
//        echo $count;
        //var_dump($rs[0]->url);
        return $count;
    }
    /**
     * 删除不争取的Url
     * @param $id
     */
    private function delIncorrectUrl($id){
        $sql = "delete from t_rssurl where id = $id";
        $this->dbh->exec($sql);
    }
    /**
     * 将争取的URL信息添加到数据库
     * @param $arr
     */
    public function addUrlInfoToDb($arr){
        $sql = "insert into t_rssurl(name,url) VALUES ('".$arr['name']."','".$arr['url']."')";
        $this->dbh->exec($sql);
    }
    /**
     * 获取category的地址并进行更新操作
     * @param $name
     */
    public function updateRssContentM($name){
//        self::getUrlName($name);
        self::getRss(self::getUrlName($name),9,8,3,1,2,3,4);
    }
    /**
     * 根据category获取url地址
     * @param $name
     * @return string $url
     */
    private function getUrlName($name){
        $sql = "select url from t_rssurl where name = '".$name."'";
        $stmt = $this->dbh->query($sql);
        $rs = $stmt->fetchAll();
        $url = $rs[0]->url;
        return $url;
    }
}
?>
