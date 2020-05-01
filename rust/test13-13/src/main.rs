//原生指针 read/write
fn main() {
    let x = "hello".to_string();
    let y : *const u8 = x.as_ptr();
    unsafe {
        assert_eq!(y.read() as char, 'h');
    }
    let x = [0, 1, 2, 3];
    let y = x[0..].as_ptr() as *const [u32; 4];//指向4个元素的数组的指针
    unsafe {
        assert_eq!(y.read(), [0, 1, 2, 3]);
    }
    let x = vec![0, 1, 2, 3];
    let y = &x as *const Vec<i32>;
    unsafe {
        assert_eq!(y.read(), [0, 1, 2, 3]);
    }
    let mut x = "";
    let y = &mut x as *mut &str;
    let z = "hello";
    unsafe {
        y.write(z);
        assert_eq!(y.read(), "hello");
    }
}
