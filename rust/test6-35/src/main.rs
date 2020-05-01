//move关键字自动实现Fn &self
fn main() {
    let s = "hello";
    let c = move || { println!("{:?}", s); };
    c();
    c();
    println!("{:?}", s);
}
