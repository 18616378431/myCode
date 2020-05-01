//函数参数模式匹配
//ref修饰的函数参数为模式匹配的不可变引用,ref mut为可变引用
#[derive(Debug)]
struct S {
    i : i32,
}

fn f(ref s : S) {
    println!("{:p}", s);
}

fn main() {
    let s = S {i : 42};
    f(s);
    // println!("{:?}", s);//s所有权发生转移
}
