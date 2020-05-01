//单生产者单消费者模式 线程间通信 channel
use std::thread;
use std::sync::mpsc::channel;

fn main() {
    let (tx, rx) = channel();
    thread::spawn(move || {
        tx.send(10).unwrap();
    });
    assert_eq!(rx.recv().unwrap(), 10);
}
