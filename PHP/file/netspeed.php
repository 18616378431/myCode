<?php
//创建文件
//$fp = fopen('test.txt','w');
//
//for($i = 0;$i < 170400;$i++){
//    fwrite($fp,"test\n");
//}
//fclose($fp);

$data = file_get_contents("test.txt");
$start = microtime(true);
$filesize = filesize("test.txt")/1024;//计算结果为kb
echo "<!--".$data."-->";
$end = microtime(true);
$duration = ($end-$start);
$speed = round($filesize/$duration,2);
echo "你的网速:$speed kb/秒\n";
?>
