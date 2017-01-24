<?php
class User {
    private static $_instance;
    private function __construct()
    {
        echo "获得一个新对象";
    }
    private function __clone()
    {
        // 覆盖clone()方法，禁止克隆
    }
    public static function getInstance()
    {
        if (! (self::$_instance instanceof self)) {
            self::$_instance = new self();
        }
        return self::$_instance;
    }
}
?>
