/**
 * 获取文件的后缀名
 * @param $file_name
 * @return bool|string
 */
function getExtend($file_name){
    $retval = "";
    $pt = strrpos($file_name,'.');
    if($pt && !is_dir($file_name)){
        $retval = substr($file_name,$pt+1,strlen($file_name)-($pt + 1));
    }else{
        return false;
    }
    return $retval;
}
