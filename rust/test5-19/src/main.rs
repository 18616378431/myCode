//闭包创建新的作用域
/// 捕获方式
/// 1.复制语义以不可变方式捕获&T
/// 2.移动语义,转移所有权
/// 3.可变绑定,在闭包中对其修改,则以可变引用&mut捕获
/// 
/// 闭包捕获外部变量根据当前上下文,而非最新值
fn main() {
    let s = "hello".to_string();
    let join = |i : &str| {s + i};//move s into closure scope
    let s = "aaa".to_string();
    assert_eq!("hello world", join(" world"));
    // println!("{:?}", s);
    // println!("{:?}", join(" world"));
}
