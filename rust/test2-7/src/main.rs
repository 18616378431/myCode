//值表达式在位置上下文中求值时会被创建临时值
fn main() {
    let mut _0: &i32;
    let mut _1: i32;
    _1 = const 42 i32;
    _0 = &_1;
}
