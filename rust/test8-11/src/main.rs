//字符串修改 追加字符串
fn main() {
    let mut hello = String::from("Hello,");
    hello.push('R');
    hello.push_str("ust!");
    assert_eq!("Hello,Rust!", hello);
}
