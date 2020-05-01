//&str的组成部分
//str由指针和长度组成,编译期就计算出大小,存储在栈上
fn main() {
    let str = "hello rust";
    let ptr = str.as_ptr();
    let len = str.len();

    println!("{:p}", ptr);
    println!("{:?}", len);
}
