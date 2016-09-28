<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2016/7/22
 * Time: 10:51
 */

/**
 * 微信扩展调用方法
 * $wx = new \WxExt\Wx\JSSDK('wxd2b119bcb219b133','28aa9f3c342c76fffc0b77fcb19d3b09 ');
 * $package = $wx->getSignPackage();
 */


/**
 * 调用接口
 * @param string $url
 * @param string $requestType
 * @param string $params 可以维数组
 * @param bool $is_json 得到的信息是否为json，是则解码
 * @return mixed|string
 */
function httpRequest($url = '',$requestType = 'GET',$params = '',$is_json = false){
    $ch = curl_init();
    curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);
    curl_setopt($ch,CURLOPT_TIMEOUT,300);
//    curl_setopt($ch,CURLOPT_SSL_VERIFYHOST,false);
//    curl_setopt($ch,CURLOPT_SSL_VERIFYPEER,false);
    curl_setopt($ch, CURLOPT_USERAGENT, 'Mozilla/5.0 (compatible; MSIE 5.01; Windows NT 5.0)');

    curl_setopt($ch,CURLOPT_HEADER,0);//请求头以信息形式返回

    curl_setopt($ch,CURLOPT_CUSTOMREQUEST,$requestType);
    if(strcmp($requestType,'POST') == 0){
        curl_setopt($ch,CURLOPT_POSTFIELDS,$params);
    }

    curl_setopt($ch,CURLOPT_URL,$url);
    $res = curl_exec($ch);
    curl_close($ch);

    return $is_json ? json_decode($res,true) : $res;
}

/**
 * 分页公共函数
 * @param
 * @string  $objName  类实例化目标表名
 * @int     $num 每页显示的纪录数量
 * @string  $strname 要截取字段名称
 * @int     $length 字段长度限制
 *
 * @param string $where 查询条件
 * @param string $order 排序条件
 *  分页查询添加字段,多表查询
 * @param string $field 要获得的字段名称,可以是表别名table.fieldname
 * @param string $table 查询的第一个表名(表全名,包含前缀t_tablename)
 * @param string $join join参数及join条件    //扩展jion条件可以为数组,不仅局限于双表联合
 * @return array
 */
function pageShow($objName,$num,$strname,$length,$where = '',$order = '',$field = '',$table = '',$join = ''){
    $obj = M($objName);
    if(!empty($where)){
        $count = $obj->where($where)->count();
        $obj->where($where);
    }else{
        $count = $obj->count();
    }
    $Page = new \Think\Page($count,$num);//实例化分页类，总纪录数和每页显示纪录数
    $Page->setConfig('prev','上一页');
    $Page->setConfig('next','下一页');
//    $Page->setConfig('first','首页');
//    $Page->setConfig('last','尾页');
    //进行分页数据查询 limit方法参数使用Page类的属性
    //排序条件
    if(!empty($order)){
        $obj->order($order);
    }else{
        $obj->order('id desc');
    }
    //多表查询####
    if(!empty($field)){//获取字段
        $obj->field($field);
    }
    if(!empty($table)){//第一个表并设置别名
        $obj->table($table);
    }
    if(!empty($join)){//join条件
        //判断$join是否为数组
        if(is_array($join)){//遍历调用
            foreach($join as $j){
                $obj->join($j);
            }
        }else{//不是数组,string类型
            $obj->join($join);
        }
    }
    //多表查询####
    $obj->limit($Page->firstRow.','.$Page->listRows);
    $list = $obj->select();
    $show = $Page->show();//分页显示输出
    //截取字符串
    for($i = 0;$i < $count;$i++){
        $String = new \Org\Util\String();
        if (strlen($list[$i][$strname]) > $length)
            $list[$i][$strname] = $String->msubstr($list[$i][$strname],0,$length + 10,'utf8',true);
    }
    $arr = array('list' => $list,'page' => $show);
    return $arr;
}

/**
 * 获取当前脚本的路径，不包含当前脚本文件名称
 * 即index.php路径
 * @return string
 */
function get_full_url() {
    $https = !empty($_SERVER['HTTPS']) && strcasecmp($_SERVER['HTTPS'], 'on') === 0 ||
        !empty($_SERVER['HTTP_X_FORWARDED_PROTO']) &&
        strcasecmp($_SERVER['HTTP_X_FORWARDED_PROTO'], 'https') === 0;
    return
        ($https ? 'https://' : 'http://').
        (!empty($_SERVER['REMOTE_USER']) ? $_SERVER['REMOTE_USER'].'@' : '').
        (isset($_SERVER['HTTP_HOST']) ? $_SERVER['HTTP_HOST'] : ($_SERVER['SERVER_NAME'].
            ($https && $_SERVER['SERVER_PORT'] === 443 ||
            $_SERVER['SERVER_PORT'] === 80 ? '' : ':'.$_SERVER['SERVER_PORT']))).
        substr($_SERVER['SCRIPT_NAME'],0, strrpos($_SERVER['SCRIPT_NAME'], '/'));
}

/**
 * get请求
 * @param $url
 * @return mixed
 */
function curlByGet($url)
{
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);    // 要求结果为字符串且输出到屏幕上
    curl_setopt($ch, CURLOPT_HEADER, 0); // 不要http header 加快效率
    curl_setopt($ch, CURLOPT_USERAGENT, 'Mozilla/5.0 (compatible; MSIE 5.01; Windows NT 5.0)');
    curl_setopt($ch, CURLOPT_TIMEOUT, 30);
    $output = curl_exec($ch);
    curl_close($ch);

    return $output;
}

/**
 * 功能：生成二维码
 * @param string $qr_data     手机扫描后要跳转的网址
 * @param string $qr_level    默认纠错比例 分为L、M、Q、H四个等级，H代表最高纠错能力
 * @param string $qr_size     二维码图大小，1－10可选，数字越大图片尺寸越大
 * @param string $save_path   图片存储路径
 * @param string $save_prefix 图片名称前缀
 */
function createQRcode($save_path,$qr_data='PHP QR Code :)',$qr_level='L',$qr_size=4,$save_prefix='qrcode'){
    if(!isset($save_path)) return '';
    //设置生成png图片的路径
    $PNG_TEMP_DIR = & $save_path;
    //导入二维码核心程序
    vendor('PHPQRcode.class#phpqrcode');
    //检测并创建生成文件夹
    if (!file_exists($PNG_TEMP_DIR)){
        mkdir($PNG_TEMP_DIR);
    }
    $filename = $PNG_TEMP_DIR.'test.png';
    $errorCorrectionLevel = 'L';
    if (isset($qr_level) && in_array($qr_level, array('L','M','Q','H'))){
        $errorCorrectionLevel = & $qr_level;
    }
    $matrixPointSize = 4;
    if (isset($qr_size)){
        $matrixPointSize = & min(max((int)$qr_size, 1), 10);
    }
    if (isset($qr_data)) {
        if (trim($qr_data) == ''){
            die('data cannot be empty!');
        }
        //生成文件名 文件路径+图片名字前缀+md5(名称)+.png
        $filename = $PNG_TEMP_DIR.$save_prefix.md5($qr_data.'|'.$errorCorrectionLevel.'|'.$matrixPointSize).'.png';
        //开始生成
        QRcode::png($qr_data, $filename, $errorCorrectionLevel, $matrixPointSize, 2);
    } else {
        //默认生成
        QRcode::png('PHP QR Code :)', $filename, $errorCorrectionLevel, $matrixPointSize, 2);
    }
    if(file_exists($PNG_TEMP_DIR.basename($filename)))
        return basename($filename);
    else
        return FALSE;
}

