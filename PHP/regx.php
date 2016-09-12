<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/9/12
 * Time: 10:23
 */

//匹配字母、数字、下划线，长度为8-20
if(preg_match('/^\w{8,20}$/','abcdefghijklmn',$matches)){
    echo "匹配正确!";
}else{
    echo "匹配失败!";
}