//非静态生命周期的类型没有实现Any 无法在运行时反射类型 'static
use std::any::Any;

struct Unstatic<'a> {
    a : &'a i32,
}

fn main() {
    let a = 42;
    let v = Unstatic{a : &a};
    let mut any : &Any;
    any = &v;
}
