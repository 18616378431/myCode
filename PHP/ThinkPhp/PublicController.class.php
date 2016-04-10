<?php
/**
 * Created by PhpStorm.
 * User: kilyal
 * Date: 15/7/18
 * Time: 上午11:05
 */
namespace Admin\Controller;
use Think\Controller;
class PublicController extends Controller{
    public function _empty(){
        echo "方法不存在!";
    }

    public function index(){

    }
    public function test(){
        //测试该模块的公共类是否实例化成功
        $t = "测试Admin模块的公共类是否实例化成功";
        return $t;
    }
    /*
     *
     * 查询企业、学生、招聘、数据库数据表数量
     * @return int 数量集合
     */
    public function getDataInfo($arr = ''){
        for($i = 0;$i < count($arr);$i++){

            if(strcmp($arr[$i],'information_schema') == 0) {
                $m = M('');
                $result = ($m->query("select count(*) as c from information_schema.tables where table_schema='manage'"));
                $cArr[$i] = $result[0]['c'];
            }else{
                $m = M($arr[$i]);
                $cArr[$i] = $m->count();
            }
        }
        //dump($cArr);
        return $cArr;
    }
    /*
     * 判断登陆状态
     */
    public function isLogin(){
        if(empty($_SESSION['admin_username'])){
            $this->error("您尚未登陆，请先登陆!",U('Admin/Login/login'));
        }
    }
    /**
     * 分页公共函数
     * @param
     * @srting $objName  类实例化目标表名
     * @int $num 每页显示的纪录数量
     * @string $strname 要截取字段名称
     * @int $length 字段长度限制
     * @array $list 分配到页面的数据变量
     * @array $page 分配到页面显示分页变量
     *
     * @param string $where 查询where条件,过滤数据,默认空
     */
    public function pageShow($objName,$num,$strname,$length,$listName,$pageName,$where = ''){
        $obj = M($objName);


        //判断where条件是否为空
        if(!empty($where)) {
            $count = $obj->where($where)->count();
            $Page = new \Think\Page($count,$num);//实例化分页类，总纪录数和每页显示纪录数
            //进行分页数据查询 limit方法参数使用Page类的属性
            $list = $obj->where("$where")->order('id desc')->limit($Page->firstRow . ',' . $Page->listRows)->select();
        }else{
            $count = $obj->count();
            $Page = new \Think\Page($count,$num);//实例化分页类，总纪录数和每页显示纪录数
            //进行分页数据查询 limit方法参数使用Page类的属性
            $list = $obj->order('id desc')->limit($Page->firstRow . ',' . $Page->listRows)->select();
        }
        //截取字符串
        for($i = 0;$i < $obj->count();$i++){
            if (strlen($list[$i][$strname]) > $length) {
                $list[$i][$strname] = mb_substr($list[$i][$strname], 0, $length + 10, 'utf8') . "...";
            }
        }
        $Page->setConfig('prev','上一页');
        $Page->setConfig('next','下一页');
        $show = $Page->show();//分页显示输出
        $this->assign($listName,$list);//赋值数据
        $this->assign($pageName,$show);//赋值分页输出
        //仅用于Company/Interview/interviewAll
        return $list;
    }
		/**
	     * 生成验证码
	     */
	    public function verify(){
            $config = array(
                'fontSize' => 30,//验证码字体大小
                'length' => 4,//验证码长度
                'useNoise' => true,//验证码杂点
            );
	        $Verify = new \Think\Verify($config);
	        $Verify->entry();
	    }
	    // 检测输入的验证码是否正确，$code为用户输入的验证码字符串
	    function check_verify($code, $id = ''){
	        $verify = new \Think\Verify();
	        return $verify->check($code, $id);
	    }

}
?>