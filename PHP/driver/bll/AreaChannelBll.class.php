<?php
/**
 * @brief   bll
 * @note    bll
 *
 * @author  jiankang.wang
 * @date    2020-05-26
 */

namespace bll;

use dal\AreaChannelDal;

class AreaChannelBll
{
    private $oAreaChannelDal;
    /**
     * @brief   构造函数
     * @note    构造函数
     *
     * @author  jiankang.wang
     * @date    2020-05-27
     */
    public function __construct()
    {
        $this->oAreaChannelDal = new AreaChannelDal();
    }

    /**
     * @brief   获取列表
     * @note    获取列表
     *
     * @author  jiankang.wang
     * @date    2020-05-27
     */
    public function getList()
    {
        return $this->oAreaChannelDal->getList();
    }

    /**
     * @brief   更新
     * @note    更新
     *
     * @author  jiankang.wang
     * @date    2020-05-27
     */
    public function updateList()
    {
        return $this->oAreaChannelDal->updateList();
    }
}