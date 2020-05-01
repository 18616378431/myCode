//所有静态生命周期均实现了Any
use std::any::Any;

struct Unstatic<'a> {
    x : &'a i32,
}

static ANSWER : i32 = 42;

fn main() {
    let v = Unstatic {x : &ANSWER};
    let mut a : &Any;
    a = &v;
    assert!(a.is::<Unstatic>());
}
