//trim_matches trim_left_matches trim_right_matches
fn main() {
    assert_eq!("Hello\tWorld\t".trim_matches('\t'), "Hello\tWorld");
    assert_eq!("11foo1bar11".trim_matches('1'), "foo1bar");
    assert_eq!("123foo1bar123".trim_matches(char::is_numeric), "foo1bar");
    let x : &[char] = &['1', '2'];
    assert_eq!("12foo1bar12".trim_matches(x), "foo1bar");
    assert_eq!("1foo1barXX".trim_matches(|c| c == '1' || c == 'X'), "foo1bar");
    assert_eq!("11foo1bar11".trim_left_matches('1'), "foo1bar11");
    assert_eq!("123foo1bar123".trim_left_matches(char::is_numeric), "foo1bar123");
    let x : &[char] = &['1', '2'];
    assert_eq!("12foo1bar12".trim_left_matches(x), "foo1bar12");
    assert_eq!("1fooX".trim_right_matches(|c| c == '1' || c == 'X'), "1foo");
}
