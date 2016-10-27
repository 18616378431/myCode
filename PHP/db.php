<?php
//���ã��ֿ��㷨
//������$id���û�accountid����jobid
//���أ���ID�� 0-($dbTotal-1)
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
//���ã�����Ͷ�ݼ�¼��ű���㷨
//������$id �û�accountid����jobid��$tbTotal ���������
//���أ���ID��(0001-1000)
function calc_hash_tb( $id )
{
    $h = sprintf("%u", crc32($id));
    $h1 = intval($h / $this->tbTotal);
    $h2 = ($h1 % $this->tbTotal) + 1;
    return sprintf("%04s",$h2);
}