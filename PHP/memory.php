
$start = time();
$startM = memory_get_usage();//此处程序开始时分配的内存

//计算出PHP当前内存大小,根据字节计算出占用内存
function convert($size)
{
    $unit=array('b','kb','mb','gb','tb','pb');
    return @round($size/pow(1024,($i=floor(log($size,1024)))),2).' '.$unit[(int)$i];
}

$endM = memory_get_usage();//此处程序结束时分配的内存
$end = time();
占用的内存为".convert($endM-$startM)
