<?php
/**
 * @brief   PDO驱动
 * @note    PDO驱动
 *
 * @author  jiankang.wang
 * @date    2020-05-26
 */

namespace dal\db;

class PdoDriver
{
    private static $aConnection = null;

    private $oPdo;

    private $oStmt;

    private $aSql;

    public function execute($aParams, $aConfig)
    {
        $aResult = ['status' => 0, 'affectrow' => 0];

        $this->init($aConfig);

        $this->aSql = $aParams;

        $this->prepareSql();

        if($aAffect = $this->prepare('execute'))
        {
            $aResult['status'] = 0;

            $aResult['affectrow'] = $aAffect;
        }
        else
        {
            //预处理失败
            $aResult['status'] = 2;
        }

        return $aResult;
    }

    public function select($aParams, $aConfig)
    {
        $aResult = ['status' => 0, 'rowcount' => 0];

        $this->init($aConfig);

        $this->aSql = [$aParams];

        $this->prepareSql();

        if($this->prepare('select'))
        {
            $aResult['status'] = 0;

            //获取执行结果
            while($aSet = $this->oStmt->fetch(\PDO::FETCH_ASSOC))
            {
                $aResult[] = $aSet;
                $aResult['rowcount']++;
            }
        }
        else
        {
            //预处理失败
            $aResult['status'] = 2;
        }

        return $aResult;
    }

    private function prepare($SelectType)
    {
        $aAffect = [];

        foreach($this->aSql as $iKey => $aSql)
        {
            $this->oStmt = $this->oPdo->prepare($aSql[0]);

            if($this->oStmt == false)
            {
                return false;
            }

            $iParamCount = isset($this->aSql[$iKey][1])?$this->aSql[$iKey][1] : 0;

            if($iParamCount > 0)
            {
                $iBind = 1;

                for($i = 2; $i < $iParamCount + 2; $i++)
                {
                    $this->oStmt->bindParam($iBind++, $this->aSql[$iKey][$i]);
                }
            }

            $this->oStmt->execute();

            if($SelectType == 'select')
            {
                break;
            }
            else//execute
            {
                $aAffect[] =  $this->oStmt->rowCount();
            }
        }

        if($SelectType == 'select')
        {
            return true;
        }
        else//execute
        {
            return $aAffect;
        }
    }

    private function init($aConfig)
    {
        $sDsn = $aConfig['type'].":host=".$aConfig['host'].";dbname=".$aConfig['dbname'];

        $sVerify = md5($sDsn . $aConfig['user'] . $aConfig['passwd']);

        if(!isset(self::$aConnection[$sVerify])) {
            try {
                //array(PDO::ATTR_PERSISTENT => true)
                self::$aConnection[$sVerify] = new \PDO($sDsn, $aConfig['user'], $aConfig['passwd']);
            } catch(\PDOException $e) {
                var_dump($e->getMessage(), $e->getCode(), $e->errorInfo, __FILE__, __LINE__);
            }
        }

        $this->oPdo = self::$aConnection[$sVerify];
    }

    private function prepareSql()
    {
        foreach($this->aSql as $iKey => $aSql)
        {
            $iParamCount = isset($this->aSql[$iKey][1])?$this->aSql[$iKey][1] : 0;

            if($iParamCount > 0)
            {
                for($i = 2; $i < $iParamCount + 2; $i++)
                {
                    $this->aSql[$iKey][$i] = key($this->aSql[$iKey][$i]);
                }

                $this->aSql[$iKey][0] = preg_replace("/:\w\d+/","?", $this->aSql[$iKey][0]);
            }
        }
    }
}