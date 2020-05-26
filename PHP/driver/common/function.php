<?php
/**
 * @brief   通用函数
 * @note    通用函数
 *
 * @author  jiankang.wang
 * @date    2020-05-26
 */

spl_autoload_register(function($sClass){
    $sPath = str_replace("\\", "/", $sClass);
    $aPath = explode("/", $sPath);
    $sClassName = array_pop($aPath);
    $sPath = implode("/", $aPath);

    $sFilePath = ROOT_PATH . DIRECTORY_SEPARATOR . $sPath . DIRECTORY_SEPARATOR . $sClassName . ".class.php";

    if(file_exists($sFilePath))
    {
        include_once($sFilePath);
    }
    else
    {
        var_dump("Class File \"$sFilePath\" Not Found!");
    }
});