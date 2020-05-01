//使用impl trait语法
//装箱:将值托管到堆内存
//拆箱:在栈内存中生成新的值

use std::fmt::Debug;

pub trait Fly {
    fn fly(&self) -> bool;
}

#[derive(Debug)]
struct Pig;

#[derive(Debug)]
struct Duck;

impl Fly for Duck {
    fn fly(&self) -> bool {
        return true;
    }
}

impl Fly for Pig {
    fn fly(&self) -> bool {
        return false;
    }
}

fn fly_static(s : impl Fly + Debug) -> bool {
    s.fly()
}

//静态分发
fn can_fly(s : impl Fly + Debug) -> impl Fly {
    if s.fly() {
        println!("{:?} can fly", s);
    } else {
        println!("{:?} can't fly", s);
    }
    s
}

//动态分发
fn dyn_can_fly(s : impl Fly + Debug + 'static) -> Box<dyn Fly> {
    if s.fly() {
        println!("{:?} can fly", s);
    } else {
        println!("{:?} can't fly", s);
    }

    Box::new(s)
}

fn main() {
    let pig = Pig;
    assert_eq!(fly_static(pig), false);
    let duck = Duck;
    assert_eq!(fly_static(duck), true);

    let pig = Pig;
    let pig = can_fly(pig);
    let duck = Duck;
    let duck = can_fly(duck);

    let pig = Pig;
    let pig = dyn_can_fly(pig);
    let duck = Duck;
    let duck = dyn_can_fly(duck);
}
