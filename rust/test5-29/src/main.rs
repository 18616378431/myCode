//无输入参数的函数且返回引用
fn return_str<'a>() -> &'a str {
    let mut s = "Rust".to_string();
    for i in 0..3 {
        s.push_str(" Good");
    }
    &s[..]
}
fn main() {
    let x = return_str();
}
