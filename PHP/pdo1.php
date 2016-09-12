<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/9/9
 * Time: 15:47
 */

$host = 'localhost';
$user = 'root';
$pwd = 'root';
$dbname=  'test';
$dsn = "mysql:host=$host;dbname=$dbname";

$dbh = new PDO($dsn,$user,$pwd);

//指定参数名称绑定参数
//$stmt = $dbh->prepare("insert into  t_test(username,passwd) values(:name,:pwd)");
//$stmt->bindParam(':name',$name);
//$stmt->bindParam(':pwd',$pass);
//$name = 'hhh';
//$pass = md5('123');
//$stmt->execute();
//$name = 'kkk';
//$pass = md5('123');
//$stmt->execute();

//不指定参数名称绑定参数重复插入数据
//$stmt = $dbh->prepare('insert into t_test(username,passwd) values(?,?)');
//$stmt->bindParam(1,$name);
//$stmt->bindParam(2,$pass);
//$name = 'ttt';
//$pass = md5('123');
//$stmt->execute();
//$name = 'aaa';
//$pass = md5('123');
//$stmt->execute();

//使用预处理获取数据
//$stmt = $dbh->prepare('select * from t_test where username = ? and passwd = ?');
//if($stmt->execute(array('aaa',md5('123')))){
//    while($row = $stmt->fetch()){
//        var_dump($row);
//    }
//}

//var_dump($stmt);
