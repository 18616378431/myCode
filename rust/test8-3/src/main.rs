//每个字符占4个字节
fn main() {
    let mut b = [0; 3];
    let tao = '道';
    let tao_str = tao.encode_utf8(&mut b);
    assert_eq!("道", tao_str);
    assert_eq!(3, tao.len_utf8());
}
