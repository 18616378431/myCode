<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/11/21
 * Time: 15:30
 */
//计算出PHP当前内存大小,根据字节计算出占用内存
function convert($size)
{
    $unit=array('b','kb','mb','gb','tb','pb');
    return @round($size/pow(1024,($i=floor(log($size,1024)))),2).' '.$unit[(int)$i];
}