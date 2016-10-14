<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/10/12
 * Time: 17:29
 */
echo "destfile=>D:\\wamp64\\www\\test\\log";

echo (floatval(1/1000000) * 100)."%";


$arr = ["destfile=>D:\\wamp64\\www\\test\\log\n",
    "destfile=>D:\\wamp64\\www\\test\\log\n",
    "destfile=>D:\\wamp64\\www\\test\\log\n",
    "destfile=>D:\\wamp64\\www\\test\\log\n"];

//echo file_put_contents('test.txt',date('Y-m-d H:i:s')."\n",FILE_APPEND|LOCK_EX);

//xdebug_debug_zval("arr");

//shell_exec('shutdown -s -t 3600');
//shell_exec('shutdown -a');

var_dump(file_exists('test.txt'));
//var_dump(filesize('test.txt'));

//exec('shutdown -s -t 5400');
//system('shutdown -a');

//passthru('shutdown -s -t 5400');

//判断php运行环境，apache运行输出apache2handler,命令行执行输出cli
var_dump(php_sapi_name());