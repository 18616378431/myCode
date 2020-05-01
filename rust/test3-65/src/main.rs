//u32类型转换为u16类型被截断处理
fn main() {
    let a = std::u32::MAX;
    let b = a as u16;
    assert_eq!(b, 65535);

    let e = -1i32;
    let f = e as u32;
    println!("{:?}", e.abs());
    println!("{:?}", f);
}
