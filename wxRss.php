 public function getRss(){
        $b = "";
        $url = "http://weirss.me/account/xiutuxi/feed/";
        $xml = file_get_contents($url);
        $p = xml_parser_create();
        xml_parser_set_option($p,XML_OPTION_SKIP_WHITE,1);
        xml_parse_into_struct($p,$xml,$values,$idx);
        xml_parser_free($p);
//        var_dump($values);
//        echo $values[9]['value'];
////        exit;
        for($i = 9,$index = 0;$i < count($values);$i += 8,$index++){
//            $data[$index]['title'] = $values[$i]['value'];

        }
//        var_dump($data);

    }
