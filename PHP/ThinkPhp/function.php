<?php
/**
 * Created by PhpStorm.
 * User: akily
 * Date: 16/4/5
 * Time: 下午1:38
 *
 *
 * 公共函数测试
 */

function test(){
    echo "公共函数测试";
}
/**
 * 分页公共函数
 * @param
 * @string  $objName  类实例化目标表名
 * @int     $num 每页显示的纪录数量
 * @string  $strname 要截取字段名称
 * @int     $length 字段长度限制
 *
 * @param string $where 查询条件
 * @param string $order 排序条件
 *  分页查询添加字段,多表查询
 * @param string $field 要获得的字段名称,可以是表别名table.fieldname
 * @param string $table 查询的第一个表名(表全名,包含前缀t_tablename)
 * @param string $join join参数及join条件    //扩展jion条件可以为数组,不仅局限于双表联合
 * @return array
 */
function pageShow($objName,$num,$strname,$length,$where = '',$order = '',$field = '',$table = '',$join = ''){
    $obj = M($objName);
    if(!empty($where)){
        $count = $obj->where($where)->count();
        $obj->where($where);
    }else{
        $count = $obj->count();
    }
    $Page = new \Think\Page($count,$num);//实例化分页类，总纪录数和每页显示纪录数
    $Page->setConfig('prev','上一页');
    $Page->setConfig('next','下一页');
    //进行分页数据查询 limit方法参数使用Page类的属性
    //排序条件
    if(!empty($order)){
        $obj->order($order);
    }else{
        $obj->order('id desc');
    }
    //多表查询####
    if(!empty($field)){//获取字段
        $obj->field($field);
    }
    if(!empty($table)){//第一个表并设置别名
        $obj->table($table);
    }
    if(!empty($join)){//join条件
        //判断$join是否为数组
        if(is_array($join)){//遍历调用
            foreach($join as $j){
                $obj->join($j);
            }
        }else{//不是数组,string类型
            $obj->join($join);
        }

    }
    //多表查询####
    $obj->limit($Page->firstRow.','.$Page->listRows);
    $list = $obj->select();

    $show = $Page->show();//分页显示输出
    //截取字符串
    for($i = 0;$i < $count;$i++){
        $String = new \Org\Util\String();
        if (strlen($list[$i][$strname]) > $length)
            $list[$i][$strname] = $String->msubstr($list[$i][$strname],0,$length + 10,'utf8',true);
    }
    $arr = array('list' => $list,'page' => $show);
    return $arr;
}
