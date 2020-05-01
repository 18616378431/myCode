//字符与标量值一一对应
fn main() {
    let tao = '道';
    let tao_u32 = tao as u32;
    assert_eq!(36947, tao_u32);
    println!("U+{:x}", tao_u32);
    println!("{}", tao.escape_unicode());

    assert_eq!(char::from(65), 'A');
    assert_eq!(std::char::from_u32(0x9503), Some('道'));
    assert_eq!(std::char::from_u32(36947), Some('道'));
    assert_eq!(std::char::from_u32(1290101), None);
}
