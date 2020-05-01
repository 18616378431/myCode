//字符串两种处理方式
//chars()字符
//bytes()字节
fn main() {
    let str = "boroos";
    let mut chars = str.chars();
    assert_eq!(Some('b'), chars.next());
    assert_eq!(Some('o'), chars.next());
    assert_eq!(Some('r'), chars.next());
    assert_eq!(Some('o'), chars.next());
    assert_eq!(Some('o'), chars.next());
    assert_eq!(Some('s'), chars.next());

    let mut bytes = str.bytes();
    assert_eq!(6, str.len());

    assert_eq!(Some(98), bytes.next());
    assert_eq!(Some(111), bytes.next());
    assert_eq!(Some(114), bytes.next());
    assert_eq!(Some(111), bytes.next());
    assert_eq!(Some(111), bytes.next());
    assert_eq!(Some(115), bytes.next());

    println!("{:?}", bytes.next());
}
