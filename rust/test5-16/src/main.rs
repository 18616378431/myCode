//if let创建新的作用域
fn main() {
    let a = Some("hello".to_string());

    if let Some(s) = a {
        println!("{:?}", s);
    }

    // println!("{:?}", a);
}
