//使用迭代器追加字符串
fn main() {
    let mut message = "Hello".to_string();
    message.extend(&[' ', 'R', 'u', 's', 't']);
    assert_eq!("Hello Rust", &message);
}
