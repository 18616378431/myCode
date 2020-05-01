//字符串内建方法
fn main() {
    assert_eq!(true, 'f'.is_digit(16));
    assert_eq!(Some(15), 'f'.to_digit(16));

    assert!('a'.is_lowercase());
    assert!(!'道'.is_lowercase());
    assert!(!'a'.is_uppercase());
    assert!('A'.is_uppercase());
    assert!(!'中'.is_uppercase());
    assert_eq!('i', 'I'.to_ascii_lowercase());
    assert_eq!('B', 'b'.to_ascii_uppercase());

    assert!(' '.is_whitespace());
    assert!('\u{A0}'.is_whitespace());
    assert!(!'越'.is_whitespace());

    assert!('a'.is_alphabetic());
    assert!('京'.is_alphabetic());
    assert!(!'1'.is_alphabetic());

    assert!('7'.is_alphanumeric());
    assert!('K'.is_alphanumeric());
    assert!('藏'.is_alphanumeric());
    //3/4

    assert!(!' '.is_control());
    assert!(!'q'.is_control());

    //7
    assert!('7'.is_numeric());
    //9
    assert!(!'藏'.is_numeric());

    println!("{}", '\r'.escape_default());




}
