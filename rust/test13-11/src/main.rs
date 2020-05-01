//创建空指针
fn main() {
    let p : *const u8 = std::ptr::null();
    assert!(p.is_null());
    let s : &str = "hello";
    let ptr : *const u8 = s.as_ptr();
    assert!(!ptr.is_null());
    let mut s = [1, 2, 3];
    let ptr : *mut u32 = s.as_mut_ptr();
    assert!(!ptr.is_null());
}
