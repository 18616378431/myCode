<?php
//作用：分库算法
//参数：$id：用户accountid或者jobid
//返回：库ID号 0-($dbTotal-1)
function calc_hash_db($id, $dbType = 'cluster' )
{
    $dbArr = array('cluster','single','pcenter','clusternew');
    if( !in_array($dbType,$dbArr))
    {
        return false;
    }

    $h = sprintf("%u", crc32($id));
    $dbid = intval(fmod($h, $this->dbTotal));
    return $dbid;
}
//作用：计算投递记录存放表的算法
//参数：$id 用户accountid或者jobid，$tbTotal 表的总数量
//返回：表ID号(0001-1000)
function calc_hash_tb( $id )
{
    $h = sprintf("%u", crc32($id));
    $h1 = intval($h / $this->tbTotal);
    $h2 = ($h1 % $this->tbTotal) + 1;
    return sprintf("%04s",$h2);
}