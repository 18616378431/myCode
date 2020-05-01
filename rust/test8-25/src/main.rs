//替代匹配 replace replacen 第三个参数为替换次数
fn main() {
    let s = "Hello\tWorld\t";
    assert_eq!("Hello World ", s.replace("\t", " "));
    assert_eq!("Hello World", s.replace("\t", " ").trim());
    let s = "this is old old 123";
    assert_eq!("this is new new 123", s.replace("old", "new"));
    assert_eq!("this is new old 123", s.replacen("old", "new", 1));
    assert_eq!("this is ald ald 123", s.replacen('o', "a", 3));
    assert_eq!("this is old old new23", s.replacen(char::is_numeric, "new", 1));
}
