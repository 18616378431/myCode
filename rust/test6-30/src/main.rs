//复制语义类型自动实现Fn
fn main() {
    let s = "hello";
    let c = || { println!("{:?}", s); };
    c();
    c();
    println!("{:?}", s);
}
