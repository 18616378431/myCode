#[derive(Debug)]
struct A {
    x: i32,
    y: i32,
}

impl A {
    fn area(&self) -> i32 {
        self.x * self.y
    }

    fn new() -> A{
        A{x:3,y:9}
    }
}

fn main() {
    let str = String::from("Hi,Rust!");
    let s = A { x: 10, y: 20 };
    let s1 = A::new();

    println!("{:?}", str);
    println!("Hello, world!");
    println!("{:?}", s);
    println!("{}", s.area());
    println!("{}",s1.area());
}
