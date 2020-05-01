//变量遮蔽并不会析构,并不等于变量生命周期提前结束
use std::ops::Drop;

#[derive(Debug)]
struct S(i32);

impl Drop for S {
    fn drop(&mut self) {
        println!("drop for {}", self.0);
    }
}

fn main() {
    let x = S(1);
    println!("create x : {:?}", x);
    
    let x = S(2);
    println!("create shadowing x : {:?}", x);
}
