<?php
function get_line( $file_name , $start , $limit )//从0开始，读取$limit行
{
    $f = new SplFileObject( $file_name,'r');
    $f->seek( $start );
    //$ret = Array();
    $ret = "";
    for( $i = 0 ; $i < $limit ; $i++ )
    {
        $ret[] = trim($f->current());
//        $ret .= $f->current();
        $f->next();
    }
    return $ret;
}

$a = get_line('delmem_00.txt',10,5);

echo "<pre>";
print_r($a);

/**************************************************************/
//通用方法
/** 返回文件从X行到Y行的内容(支持php5、php4)  
 * @param string $filename 文件名
 * @param int $startLine 开始的行数
 * @param int $endLine 结束的行数
 * @return string
 */
function getFileLines($filename, $startLine = 1, $endLine=50, $method='rb') {
    $content = array();
    $count = $endLine - $startLine;  
    // 判断php版本（因为要用到SplFileObject，PHP>=5.1.0）
    if(version_compare(PHP_VERSION, '5.1.0', '>=')){
        $fp = new SplFileObject($filename, $method);
        $fp->seek($startLine-1);// 转到第N行, seek方法参数从0开始计数
        for($i = 0; $i <= $count; ++$i) {
            $content[]=$fp->current();// current()获取当前行内容
            $fp->next();// 下一行
        }
    }else{//PHP<5.1
        $fp = fopen($filename, $method);
        if(!$fp) return 'error:can not read file';
        for ($i=1;$i<$startLine;++$i) {// 跳过前$startLine行
            fgets($fp);
        }
        for($i;$i<=$endLine;++$i){
            $content[]=fgets($fp);// 读取文件行内容
        }
        fclose($fp);
    }
    return array_filter($content); // array_filter过滤：false,null,''
}
