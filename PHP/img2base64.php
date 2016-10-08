<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/10/8
 * Time: 11:21
 */

if(0){
    header("Content-type:image/jpeg");
    $psize = filesize("water.jpg");
    $pdata = fread(fopen('water.jpg','r'),$psize);

    $txt = base64_encode($pdata);
    file_put_contents('zhuanhuan.txt',$txt);
}

//header("Content-type:image/jpeg");
//$file = file_get_contents("zhuanhuan.txt");
//$data = base64_decode($file);
//echo $data;

if(!empty($_FILES)){
//    var_dump($_FILES);
//    $size = filesize($_FILES['file']['tmp_name']);
//    $data = fread(fopen($_FILES['file']['tmp_name'],'r'),$size);
//    $txt = base64_encode($data);
//    file_put_contents('zhuanhuan.txt',$txt);

//多文件上传,将每个文件信息整理进同一数组
//    for($i = 0;$i < count($_FILES['file']['tmp_name']);$i++){
//        $newarr[$i][] = $_FILES['file']['name'][$i];
//        $newarr[$i][] = $_FILES['file']['type'][$i];
//        $newarr[$i][] = $_FILES['file']['tmp_name'][$i];
//        $newarr[$i][] = $_FILES['file']['error'][$i];
//        $newarr[$i][] = $_FILES['file']['size'][$i];
//    }
//    echo "<pre>";
//    print_r($newarr);


//    file_put_contents('zhuanhuan.txt',img2base64($_FILES['file']['tmp_name']));
//    echo img2base64($_FILES['file']['tmp_name']);
}
//header("Content-type:image/jpeg");



//$file = file_get_contents("zhuanhuan.txt");
//echo "<img src=".$file." >";

//针对上传文件进行修改,$_FILES['file']['tmp_name']:D:\wamp64\tmp\php691E.tmp
//专用于img标签src
function img2base64($img_file){
    $img_base64 = "";
    $img_type = "";
    $img_info = getimagesize($img_file);
//    var_dump($img_info);
    $fp = fopen($img_file,'r');
    if($fp){
        $file_content = base64_encode(fread($fp,filesize($img_file)));
        switch($img_info[2]){
            case 1:
                $img_type = "git";
                break;
            case 2:
                $img_type = "jpeg";
                break;
            case 3:
                $img_type = "png";
                break;
        }
        $img_base64 = 'data:image/'.$img_type.';base64,'.$file_content;//合成图片base64
        fclose($fp);
    }
    return $img_base64;
}
