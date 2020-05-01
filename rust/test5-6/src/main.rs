//复合结构 复制语义
#[derive(Debug)]
struct A {
    a : i32,
    b : i32,
}

fn main() {
    let a = A {a : 1, b : 2};
    let b = a;//所有权发生转移

    println!("{:?}", a);
}
