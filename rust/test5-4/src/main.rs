//Box<T>无法实现Copy
#[derive(Copy, Clone)]
struct A {
    a : i32,
    b : Box<i32>,
}

fn main() {
    println!("Hello, world!");
}
