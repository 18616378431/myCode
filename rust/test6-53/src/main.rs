//for<'f>语法 高阶生命周期,高阶trait限定
use std::fmt::Debug;

trait DoSomething<T> {
    fn do_sth(&self, value : T);
}

impl<'a, T : Debug> DoSomething<T> for &'a usize {
    fn do_sth(&self, value : T) {
        println!("{:?}", value);
    }
}

fn bar(b :Box<for<'f> DoSomething<&'f usize>>) {
    let s : usize = 10;
    b.do_sth(&s);
}

fn main() {
    let x = Box::new(&2usize);
    bar(x);
}
