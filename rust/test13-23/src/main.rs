//dropck
use std::fmt;
#[derive(Debug, Clone, Copy)]
enum State {
    InValid,
    Valid,
}

#[derive(Debug)]
struct Hello<T : fmt::Debug>(&'static str, T, State);

impl<T : fmt::Debug> Hello<T> {
    fn new(name : &'static str, t : T) -> Self {
        Hello(name, t, State::Valid)
    }
}

impl<T : fmt::Debug> Drop for Hello<T> {
    fn drop(&mut self) {
        println!("drop Hello({} {:?} {:?})", self.0, self.1, self.2);
        self.2 = State::InValid;
    }
}

struct WrapBox<T> {
    v : Box<T>,
}

impl<T> WrapBox<T> {
    fn new(t : T) -> Self {
        WrapBox{v : Box::new(t)}
    }
}

fn f1() {
    let x;let y;
    // let (x, y);
    x = Hello::new("x", 13);
    y = WrapBox::new(Hello::new("y", &x));
}

fn main() {
    f1();
}
