//字符类型示例
fn main() {
    let x = 'r';
    let x = 'U';

    println!("{}", '\'');
    println!("{}", '\\');
    println!("{}", '\n');
    println!("{}", '\r');
    println!("{}", '\t');

    assert_eq!('\x2A', '*');
    assert_eq!('\x25', '%');
    // assert_eq!('\u{CA0}', '');
    // assert_eq!('\u{151}', '');
    assert_eq!('%' as i8, 37);
    // assert_eq!('@' as i8, -96);
}
