//Rc指针实现Deref
use std::rc::Rc;

fn main() {
    let x = Rc::new("Hello");
    println!("{:?}", x.chars());
}
