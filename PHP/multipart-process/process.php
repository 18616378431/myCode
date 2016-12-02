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
    $command = "$phpPath $destPHPFile >> $logFile &";//添加&符号程序后台运行
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
    $cmd = 'ps -ef | grep "log.php" | grep -v "grep" | wc -l';//shell命令获取执行脚本进程数量
    while(shell_exec($cmd) >= 5){//5进程并发运行
	sleep(1);
    }
    usleep(300);//延迟300ms，防止同时创建文件夹冲突导致程序失败
}
$cmd = 'ps -ef | grep "log.php" | grep -v "grep" | wc -l';//shell命令获取执行脚本进程数量
while(shell_exec($cmd) >= 1){//等待全部进程执行完毕
	sleep(1);
}
$end = time();
echo "成功启动".$success."个进程\n";
echo "失败启动".$failure."个进程\n";
echo $i."个进程，共花费时间".($end-$start)."s,".round(($end-$start)/60,2)."分钟\n";
