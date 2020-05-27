<?php
/**
 * @brief   index
 * @note    index
 *
 * @author  jiankang.wang
 * @date    2020-05-26
 */

include "../root.php";
include_once(ROOT_PATH . "/config/bootstrap.php");

use bll\AreaChannelBll;
use dal\db\DBDriver;

//$oPdoDriver = new PdoDriver();

//$aMysqlConfig = include_once(ROOT_PATH . "/config/areachannel/mysql.config.php");


//echo "<pre>";
//print_r($aMysqlConfig);
//exit;

//select
//$aInput = [
//    'select * from t_user where id >= :x1 and id <= :x2 order by id desc',
//    2,
//    [1 => 'i'],
//    [3 => 'i']
//];

//$aResult = $oPdoDriver->select($aInput, $aMysqlConfig['mysql']['master']);

//$aResult = DBDriver::init("select")->select($aInput, $aMysqlConfig['mysql']['master']);
//
//echo "<pre>";
//print_r($aResult);

//execute
//$aInput = [
//    [
//        'update t_user set name = ? where id = ?',
//        2,
//        ['aaa' => 's'],
//        [1 => 'i']
//    ],
//    [
//        'update t_user set name = ? where id = ?',
//        2,
//        ['bbb' => 's'],
//        [2 => 'i']
//    ],
//    [
//        'update t_user set name = ? where id = ? or id = ?',
//        3,
//        ['ccc' => 's'],
//        [3 => 'i'],
//        [4 => 'i'],
//    ]
//];

//$aResult = $oPdoDriver->execute($aInput, $aMysqlConfig['mysql']['master']);

//$aResult = DBDriver::init('execute')->execute($aInput, $aMysqlConfig['mysql']['master']);
//
//echo "<pre>";
//print_r($aResult);
//exit;

$oAreaChannelBll = new AreaChannelBll();

$aList = $oAreaChannelBll->getList();

$aUpdateList = $oAreaChannelBll->updateList();

echo "<pre>";
print_r($aList);
print_r($aUpdateList);
//exit;

