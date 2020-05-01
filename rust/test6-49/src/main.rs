//使用FnBox代替FnOnce
#![feature(fnbox)]
use std::boxed::FnBox;

fn square() -> Box<FnBox(i32) -> i32> {
    Box::new(|i| {i * i})
}

fn main() {
    let square = square();
    assert_eq!(4, square(2));
}
