//连接字符串 + += String类型实现了Add<&str> AddAssign<&str>
fn main() {
    let left = "the tao".to_string();
    let mut right = "Rust".to_string();
    assert_eq!(left + " of " + &right, "the tao of Rust");
    right += "!";
    assert_eq!("Rust!", right);
}
