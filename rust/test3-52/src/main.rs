//多线程间共享可变变量
use std::thread;

fn main() {
    let mut x = vec![1,2,3,4];

    thread::spawn(|| {
        x.push(5);
    });

    x.push(2);
}
