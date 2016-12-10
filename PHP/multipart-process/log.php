<?php
echo "PID:".getmypid()."\n";
echo "开始时间:".$start = date('Y-m-d H:i:s')."\n";

$mydir = 'tmp/0305';
if(!is_dir($mydir)){
	if(!mkdir($mydir,0777,true)){
        echo "文件夹创建失败!\n";
    }
}

sleep(10);

echo "结束时间:".$end = date('Y-m-d H:i:s')."\n";

