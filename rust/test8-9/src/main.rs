//get get_mut 获取字符串切片
fn main() {
    let mut v = String::from("boroos道");
    assert_eq!(Some("b"), v.get(0..1));
    assert_eq!(Some("道"), v.get(6..9));
    assert_eq!(Some("oroos道"), v.get(1..));

    assert!(v.get_mut(7..).is_none());
    assert!(!v.is_char_boundary(7));
    assert!(v.get_mut(..8).is_none());
    assert!(v.get_mut(..42).is_none());
}
