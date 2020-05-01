//组成String类型的三部分
//as_ptr,len,capacity
fn main() {
    let mut a = String::from("foo");
    println!("{:p}", a.as_ptr());
    println!("{:p}", &a);
    assert_eq!(3, a.len());
    a.reserve(10);
    assert_eq!(13, a.capacity());
}
