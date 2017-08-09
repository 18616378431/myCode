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
     * 遍历rss地址数组、将当前最热weirss全部写入数据库
     * MacTalk:http://weirss.me/account/sagacity-mac/feed/
     * 商业周刊中文版:http://weirss.me/account/businessweek/feed/
     * 媒体札记:http://weirss.me/account/xdnmtzj/feed/
     * 高可用架构:http://weirss.me/account/gh_ef1c37a72e61/feed/
     * 千喜来客:http://weirss.me/account/gh_7b58526fbbe6/feed/
     *
     */
    public function weiRssAll(){
        $weirssArr = array("http://weirss.me/account/sagacity-mac/feed/"
                            ,"http://weirss.me/account/businessweek/feed/"
                            ,"http://weirss.me/account/xdnmtzj/feed/"
                            ,"http://weirss.me/account/gh_ef1c37a72e61/feed/"
                            ,"http://weirss.me/account/gh_7b58526fbbe6/feed/");
        for($i = 0;$i < count($weirssArr);$i++){
//            $this->wx->getRss("http://weirss.me/account/xiutuxi/feed/",9,8,3,1,2,3,4);
//            self::getRss($weirssArr[$i],9,8,3,1,2,3,4);
//            self::rssDebug($weirssArr[$i]);
            echo $weirssArr[$i];
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
            }
        }
//        var_dump($data);
        self::addAll($data);

    }
    /**
     * 遍历二维数组并全部写入数据库
     * @param array $data
     */
    private function addAll($data){
        foreach($data as $d){
            //$this->dbh->insert('t_wxrss')->data($d)->exec();
            $sql = "insert into t_wxrss(title,link,author,content,publishdate) VALUES ('".$d['title']."','".$d['link']."','".$d['author']."','".$d['content']."','".$d['publishdate']."')";
            $this->dbh->exec($sql);
        }
    }
    /*************微信RSS源 End AUTH WJK****************/

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
     */
    public function getSecondPage(){
        $urls = self::getPageContent("http://weirss.me/account/sagacity-mac");
        var_dump($urls[0]);
        $str = "http://weirss.me".$urls[0];//ROOT
        $urlsA = self::rssDebug("$str");
        var_dump($urlsA);
    }
