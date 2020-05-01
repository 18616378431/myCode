//内部可变性Cell<T>
/// get按位复制实现了Copy的值
/// 未实现Copy的则提供了get_mut方法返回可变借用
/// set 对于任何类型均可
use std::cell::Cell;

struct Foo {
    x : u32,
    y : Cell<u32>,
}

fn main() {
    let foo = Foo {x : 1, y : Cell::new(3)};
    assert_eq!(1, foo.x);
    assert_eq!(3, foo.y.get());
    foo.y.set(5);
    assert_eq!(5, foo.y.get());
}
