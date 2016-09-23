<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/9/23
 * Time: 15:58
 */

$upload_path = 'uploads/';
$allow_type = array('gif','jpg','jpeg','bmp','png');
$allow_size = 1000000;

if(isset($_FILES)){
    //判断文件大小
    if($_FILES['file']['size'] > $allow_size){
        die("文件太大无法上传");
    }
    //获取文件后缀判断类型是否正确
    $ext = getExt($_FILES['file']['name']);
    if($ext === false){
        die("获取文件后缀失败");
    }else if($ext && in_array($ext,$allow_type)){
        echo "文件后缀获取成功，为$ext";
    }else{
        echo "文件后缀获取成功,类型不正确，为$ext";exit;
    }
    //判断上传目录是否存在并创建
    if(!is_dir($upload_path)){
        if(!@mkdir($upload_path,0775,false)){
            die("创建上传文件目录失败");
        }
    }
    //判断文件是否正确上传
    if($_FILES['file']['error'] != 0){
        die("文件上传错误");
    }
    //将临时文件上传至指定目录
    if(!move_uploaded_file($_FILES['file']['tmp_name'],$upload_path.$_FILES['file']['name'])){
        die("文件上传失败");
    }else{
        echo "文件上传成功";
    }
}
//获取文件后缀
function getExt($filename){
    $pos = strrpos($filename,'.');
    if($pos){
        $retval = substr($filename,$pos+1,strlen($filename)-($pos+1));
        return $retval;
    }else{
        return false;
    }
}

?>