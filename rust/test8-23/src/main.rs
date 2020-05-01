//trim 取出字符串两边的空格、制表符、换行符 trim_left trim_right
fn main() {
    let s = " Hello\tWorld\t";
    assert_eq!("Hello\tWorld", s.trim());
    assert_eq!("Hello\tWorld\t", s.trim_left());
    assert_eq!(" Hello\tWorld", s.trim_right());
}
