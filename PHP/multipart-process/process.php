<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/10/18
 * Time: 16:21
 */
set_time_limit(0);
ini_set('memory_limit','2048M');

$start = time();

$phpPath = '/usr/local/php/bin/php';
$destPHPFile = 'log.php';
$logFile = 'log.txt';


$success = $failure = 0;

//启动2个进程
for($i = 0;$i < 17;$i++){
    $command = "$phpPath $destPHPFile >> $logFile &";
    echo "进程".$i."开启时间".date('Y-m-d H:i:s')."\n";
    $pstart = time();
    $resource = popen($command,'r');
    if(is_resource($resource)){
        $success++;
        pclose($resource);
        $pend = time();
        echo date('Y-m-d H:i:s')."进程:".$i."启动完毕,耗费".($pend-$pstart)."s,".round(($pend-$pstart)/60,2)."分钟,执行完毕并关闭\n";
    }else{
        $failure++;
    }
    while(shell_exec($cmd) >= 6){//包含一个启动进程，子进程为6-1
        sleep(1);
    }
	usleep(300);//延迟300ms，防止同时创建文件夹冲突导致程序失败
}

$end = time();
echo "成功启动".$success."个进程\n";
echo "失败启动".$failure."个进程\n";
echo $i."个进程，共花费时间".($end-$start)."s,".round(($end-$start)/60,2)."分钟\n";
