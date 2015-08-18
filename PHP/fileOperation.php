<?php
/**
 * 获取文件的后缀名
 * @param $file_name
 * @return bool|string
 */
function getExtend($file_name){
    $pt = strrpos($file_name,'.');//获取.在字符串中最后一次出现的位置，返回下标位置
    if($pt){
        $retval = substr($file_name,$pt+1,strlen($file_name)-($pt + 1));//截取字符串，获取后缀字符串
    }else{
        return false;
    }
    return $retval;
}
/**
 * 只保留文件夹中的目标文件
 * @param $dir 目标目录的相对或绝对路径
 */
function clear($dir){
    $dirPath = realpath($dir);//目标目录的绝对路径
    $fileNames = scandir($dir);//遍历文件夹，返回结果存储在数组中
    foreach($fileNames as $fileName) {
        if ($fileName == '.' || $fileName == '..')
            continue;
        $file = $dirPath . DIRECTORY_SEPARATOR . $fileName;
        if (is_dir($file)) {//是文件夹则递归
            clear($file);
            rmdir($file);//注释即保留目录结构，不注释则只保留目标文件
        } else {
            $arr = array('c', 'h','ico','jpg','png','wav','mp3');//要保留的文件类型
            $rs = getExtend($file);//获取后缀
            if (!in_array($rs, $arr)) {//取得整个目录下不符合标准的全部文件名称
                unlink($file);//删除文件
            }
        }
    }
}
clear($dir);
?>
?>
