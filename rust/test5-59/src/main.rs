//标签trait Send:可在线程间安全传递
//Sync,在线程间安全共享
//线程不安全
use std::thread;

fn main() {
    let mut data = vec![1, 2, 3];
    
    for i in 0..3 {
        thread::spawn(move || {
            data[i] += i;
        });
    }

    thread::sleep_ms(50);
}
