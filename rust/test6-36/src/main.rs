//环境变量为移动语义时使用move关键字
fn main() {
    let s = "hello".to_string();
    let c = move || { println!("{:?}", s); };
    c();
    c();
    // println!("{:?}", s);
}
