<?php
/**
 * Created by PhpStorm.
 * User: akily
 * Date: 17/4/2
 * Time: 下午7:16
 *
 * note:swoole扩展实现在线聊天室
 * brief:服务端
 */
//websocket对象
$oWs = new swoole_websocket_server("192.168.2.130",9502);
//设置配置
$aConfig = [
    'daemonize'     => false,//是否是守护进程
    'max_request'   => 10000,//最大连接数量
    'dispatch_mode' => 2,
    'debug_mode'    => 1,
    //心跳检测设置,自动踢掉掉线的fd
    'heartbeat_check_interval'  => 5,
    'heaetbeat_idle_time'       => 600,

];
$oWs->set($aConfig);
//监听websocket消息事件,其他:swoole提供了bind方法,支持uid和fd绑定
$oWs->on("message",function($oWs,$frame){
    $msg = 'from'.$frame->fd.":{$frame->data}\n";
    //分批次发送
    $start_fd = 0;
    while(true){
        //connection_list函数获取现在连接中的fd
        //获取从fd之后100个进行发送
        $conn_list = $oWs->connection_list($start_fd,100);
        echo "conn_list:";
        var_dump($conn_list);
        echo "count:".count($conn_list)."\n";
        if($conn_list === false || count($conn_list) == 0){
            echo "finish\n";
            return 0;
        }
        $start_fd = end($conn_list);
        foreach($conn_list as $fd){
            $oWs->push($fd,$msg);
        }
    }
});
//监听websocket连接关闭事件
$oWs->on("close",function($oWs,$fd){
//    echo "client-{$fd} is closed\n";
    //销毁fd连接信息
    $oWs->close($fd);
});
//开始websocket服务
$oWs->start();

