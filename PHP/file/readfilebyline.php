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
?>
