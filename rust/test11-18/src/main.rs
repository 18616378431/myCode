//使用Rc共享所有权
use std::rc::Rc;
use std::thread;

fn main() {
    let mut s = Rc::new("Hello".to_string());
    for _ in 0..3 {
        let mut s_clone = s.clone();
        thread::spawn(move || {
            s_clone.push_str(" hello");
        });
    }
}
