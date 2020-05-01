//使用mut声明可变绑定
fn main() {
    let mut x = "hello".to_string();
    x += " world";
    assert_eq!("hello world", x);
}
