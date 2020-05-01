//简单自旋锁
use std::thread;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::Arc;

fn main() {
    let spinlock = Arc::new(AtomicUsize::new(1));
    let spinlock_clone = spinlock.clone();
    let thread = thread::spawn(move || {
        spinlock_clone.store(0, Ordering::SeqCst);
    });
    while spinlock.load(Ordering::SeqCst) != 0 {

    }
    if let Err(panic) = thread.join() {
        println!("Thread had an error : {:?}", panic);
    }
}
