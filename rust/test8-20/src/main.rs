//位置匹配
fn main() {
    let s = "Lowe 老虎 Leopard";
    assert_eq!(s.find('w'), Some(2));
    assert_eq!(s.find('老'), Some(5));
    assert_eq!(s.find('虎'), Some(8));
    assert_eq!(s.find('e'), Some(3));
    assert_eq!(s.find("Leopard"), Some(12));
    assert_eq!(s.rfind('L'), Some(12));
    assert_eq!(s.find(char::is_whitespace), Some(4));
    assert_eq!(s.find(char::is_lowercase), Some(1));
}
