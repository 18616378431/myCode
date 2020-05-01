//channel死锁
use std::sync::mpsc::channel;
use std::thread;

fn main() {
    let (tx, rx) = channel();
    for i in 0..5 {
        let tx = tx.clone();
        thread::spawn(move || {
            tx.send(i).unwrap();
        });
    }

    drop(tx);//tx未析构 rx.iter不返回None 等待消息 循环不停止 
    for j in rx.iter() {
        println!("{:?}", j);
    }
}
