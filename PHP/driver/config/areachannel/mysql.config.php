<?php
/**
 * @brief   mysql配置文件
 * @note    mysql配置文件
 *
 * @author  jiankang.wang
 * @date    2020-05-26
 */

return array(
    'mysql' => [
        'master' => [
            'type'      => 'mysql',
            'host'      => '127.0.0.1',
            'dbname'    => 'driver',
            'user'      => 'root',
            'passwd'    => 'root',
            'charset'   => 'utf8'
        ],
        'slave' => [
            'type'      => 'mysql',
            'host'      => '127.0.0.1',
            'dbname'    => 'driver',
            'user'      => 'root',
            'passwd'    => 'root',
            'charset'   => 'utf8'
        ]
    ],
    'oracle' => [

    ]
);