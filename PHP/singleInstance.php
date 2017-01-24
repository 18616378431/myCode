<?php
class User {
    protected $user_name;
    public static $instance;
    
    private function __construct() {}  // 私有构造函数，避免多次创建对象，导致对象的不唯一
    private function clone() {}  // 避免克隆（保证单例对象的唯一性）

    public static function getInstance() { 
        if (null === self::$instance) {
            self::$instance = new self(); 
        }
        return self::$instance;
    }
}
?>
