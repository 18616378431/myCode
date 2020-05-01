//字符串删除 remove,drain,find,truncate,clear,
fn main() {
    let mut s = String::from("hallo");
    s.remove(3);
    assert_eq!("halo", s);
    assert_eq!(Some('o'), s.pop());
    assert_eq!(Some('l'), s.pop());
    assert_eq!(Some('a'), s.pop());
    assert_eq!("h", s);

    let mut s = String::from("hallo");
    s.truncate(3);
    assert_eq!("hal", s);
    s.clear();
    assert_eq!("", s);

    let mut s = String::from("a is alpha,b is beta");
    let beta_offset = s.find('b').unwrap_or(s.len());
    let t : String = s.drain(..beta_offset).collect();
    assert_eq!("a is alpha,", t);
    assert_eq!("b is beta", s);
    s.drain(..);
    assert_eq!(s, "");
}
