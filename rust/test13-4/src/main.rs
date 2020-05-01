//unsafe 块 
//unsafe函数或方法仅能够在unsafe块中进行调用
fn main() {
    let hello = vec![104, 101, 108, 108, 111];
    let hello = unsafe {
        String::from_utf8_unchecked(hello)
    };
    // let hello = String::from_utf8_unchecked(hello);

    assert_eq!("hello", hello);
}
