<?php
/**
 * 获取文件的后缀名
 * @param $file_name
 * @return bool|string
 */
function getExtend($file_name){
    $pt = strrpos($file_name,'.');
    if($pt){
        $retval = substr($file_name,$pt+1,strlen($file_name)-($pt + 1));
    }else{
        return false;
    }
    return $retval;
}
/**
 * 只保留文件夹中的目标文件
 * @param $dir
 */
function clear($dir){
    $dirPath = realpath($dir);
    $fileNames = scandir($dir);
    foreach($fileNames as $fileName) {
        if ($fileName == '.' || $fileName == '..')
            continue;
        $file = $dirPath . DIRECTORY_SEPARATOR . $fileName;
        if (is_dir($file)) {
            clear($file);
            rmdir($file);
        } else {
            $arr = array('c', 'h','ico','jpg','png','wav','mp3');
            $rs = getExtend($file);
            if (!in_array($rs, $arr)) {//取得整个目录下不符合标准的全部文件名称
                unlink($file);
            }
        }
    }
}
clear($dir);
?>
?>
