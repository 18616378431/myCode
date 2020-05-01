//使用Extend迭代器追加字符串
fn main() {
    let mut message = String::from("hello");
    message.extend([',', 'r', 'u'].iter());
    message.extend("st ".chars());
    message.extend("w o r l d".split_whitespace());
    assert_eq!("hello,rust world", message);
}
