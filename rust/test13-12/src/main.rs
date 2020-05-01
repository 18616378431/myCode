//使用offset方法
fn main() {
    let s : &str = "Rust";
    let ptr : *const u8 = s.as_ptr();
    unsafe {
        println!("{:?}", *ptr.offset(1) as char);//u
        println!("{:?}", *ptr.offset(3) as char);//t
        println!("{:?}", *ptr.offset(255) as char);//?
    }
}
