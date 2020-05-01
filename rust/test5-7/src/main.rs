//手动为结构体实现Copy trait
#[derive(Debug, Copy, Clone)]
struct A {
    a : i32,
    b : i32,
}

fn main() {
    let a = A {a : 1, b : 2};
    let b = a;

    println!("{:?}", a);
}
