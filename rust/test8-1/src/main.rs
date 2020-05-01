//字节序列
use std::str;

fn main() {
    let tao = str::from_utf8(&[0xE9u8, 0x81u8, 0x93u8]).unwrap();
    assert_eq!("道", tao);
    assert_eq!("道", String::from("\u{9053}"));
    let unicode_x = 0x9053;
    let utf_x_hex = 0xe98193;
    let utf_x_bin = 0b111010011000000110010011;
    println!("unicode_x : {:b}", unicode_x);
    println!("utf_x_hex : {:b}", utf_x_hex);
    println!("utf_x_bin : 0x{:x}", utf_x_bin);
}
