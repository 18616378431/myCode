<?php
/**
 * @brief   数据库驱动工厂
 * @note    数据库驱动工厂
 *
 * @author  jiankang.wang
 * @date    2020-05-26
 */

namespace dal\db;

use dal\db\PdoDriver;

class DBDriver
{
    private static $aDbObject;

    public static function init($sType)
    {
        if(!isset(self::$aDbObject[$sType]))
        {
            $oPdoDriver = new PdoDriver();

            self::$aDbObject[$sType] = $oPdoDriver;
        }

        return self::$aDbObject[$sType];
    }
}