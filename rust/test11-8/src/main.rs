//创建线程
use std::thread;

fn main() {
    let mut v = vec![];
    for id in 0..5 {
        let child = thread::spawn(move || {
            println!("in child : {}", id);
        });
        v.push(child);
    }
    println!("in main: before join");
    for child in v {
        child.join();
    }
    println!("in main : after join");
}
