<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/9/8
 * Time: 18:00
 */

echo "test file for PHP!";

var_dump(gd_info());


$host = 'localhost';
$user = 'root';
$pwd = 'root';
$dbname = 'test';
$dsn = "mysql:host=$host;dbname=$dbname";

try{
    $pdo = new PDO($dsn,$user,$pwd,array(PDO::ATTR_PERSISTENT=>true));
    $pdo->setAttribute(PDO::ATTR_CASE,PDO::CASE_UPPER);
    $sql = "select * from t_user";
    $pdo->query('set names utf8;');
    $result = $pdo->query($sql);
    $result->setFetchMode(PDO::FETCH_ASSOC);
//    var_dump($result);
    echo "<pre>";
    foreach($result as $r){
        print_r($r);
    }
}catch(PDOException $e){
    die($e->getMessage());
}


function getExt($file){
    $pos = strrpos($file,'.');
    if($pos){
        $retval = substr($file,$pos+1,strlen($file)-($pos+1));
        return $retval;
    }else{
        return false;
    }
}
//echo getExt('123456.jpg');
function clear($dir,$type){
    $dirPath = realpath($dir);
    $files = scandir($dir);
    foreach($files as $k=>$v){
        if('.' == $v || '..' == $v){
            continue;
        }
        $file = $dirPath.DIRECTORY_SEPARATOR.$v;
        if(is_dir($file)){
            clear($file,$type);
            @rmdir($file);
        }else{
            $ext = getExt($file);
            if(!in_array($ext,$type)){
                unlink($file);
            }
        }
    }
}
$arr = ['php'];
clear('./www',$arr);
