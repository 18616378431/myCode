//使用Arc共享所有权
use std::sync::Arc;
use std::thread;

fn main() {
    let s = Arc::new("Hello".to_string());
    for _ in 0..3 {
        let s_clone = s.clone();
        thread::spawn(move || {
            s_clone.push_str(" hello");
        });
    }
}
