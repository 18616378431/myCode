<?php
/**
 * @brief   dal
 * @note    dal
 *
 * @author  jiankang.wang
 * @date    2020-05-26
 */

namespace dal;

use dal\db\DBDriver;

class AreaChannelDal
{
    private $aMysqlConfig;

    public function __construct()
    {
        $this->aMysqlConfig = include ROOT_PATH . "/config/areachannel/mysql.config.php";
    }

    public function getList()
    {
        $aInput = [
            'select * from t_user where id >= :x1 and id <= :x2 order by id desc',
            2,
            [1 => 'i'],
            [3 => 'i']
        ];

        return DBDriver::init("select")->select($aInput, $this->aMysqlConfig['mysql']['slave']);
    }

    public function updateList()
    {
        $aInput = [
            [
                'update t_user set name = ? where id = ?',
                2,
                ['aaa' => 's'],
                [1 => 'i']
            ],
            [
                'update t_user set name = ? where id = ?',
                2,
                ['bbb' => 's'],
                [2 => 'i']
            ],
            [
                'update t_user set name = ? where id = ? or id = ?',
                3,
                ['ccc' => 's'],
                [3 => 'i'],
                [4 => 'i'],
            ]
        ];

        return DBDriver::init('execute')->execute($aInput, $this->aMysqlConfig['mysql']['master']);
    }
}