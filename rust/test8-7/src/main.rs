//创建String的方法
fn main() {
    let string : String = String::new();
    assert_eq!("", string);
    let string : String = String::from("Hello Rust");
    assert_eq!("Hello Rust", string);
    //分配20个单位的空间,实际大小为单个字符占用字节数x20
    let string : String = String::with_capacity(20);
    assert_eq!("", string);
    let str : &'static str = "the tao of rust";
    let string : String = str.chars().filter(|c| !c.is_whitespace()).collect();
    assert_eq!("thetaoofrust", string);
    let string : String = str.to_owned();//to_string()
    assert_eq!("the tao of rust", string);
    let string : String = str.to_string();
    let str : &str = &str[11..15];
    assert_eq!("rust", str);
}
