//编译期对原生类型按位复制
fn main() {
    let x = 5;
    let y = x;
    assert_eq!(x, 5);
    assert_eq!(y, 5);
}
