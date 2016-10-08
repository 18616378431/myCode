<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/10/8
 * Time: 9:35
 */

//发牌器

$arr = array();
for($i = 0;$i < 54;$i++){
    $arr[$i] = $i+1;
}

echo "<pre>";
print_r($arr);

shuffle($arr);
print_r($arr);

$player1 = array();
$player2 = array();
$player3 = array();
for($i = 0;$i < count($arr);$i++){
    $mod = $i % 3;//012
    switch($mod){
        case 0:
            $player1[] = $arr[$i];
            break;
        case 1:
            $player2[] = $arr[$i];
            break;
        case 2:
            $player3[] = $arr[$i];
            break;
        default:
            echo "发牌失败";
            break;
    }
}

rsort($player1);
rsort($player2);
rsort($player3);

print_r($player1);
print_r($player2);
print_r($player3);
