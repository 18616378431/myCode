//解引用裸指针 *const String,*mut String
//&s as ...
fn main() {
    let mut s = "hello".to_string();
    let r1 = &s as *const String;
    let r2 = &mut s as *mut String;
    assert_eq!(r1, r2);
    let address : u64 = 0x7fff1d72307d;
    let r3 = address as *const String;
    unsafe {
        println!("r1 is {}", *r1);
        println!("r2 is {}", *r2);
        //段错误
        assert_eq!(*r1, *r3);
    };
}
