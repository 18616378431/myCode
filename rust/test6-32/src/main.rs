//实现了Fn的闭包可以显式调用FnMut和FnOnce
//复制语义 不可变借用&T
//移动语义 转移所有权
// #![feature(fn_traits)]

fn main() {
    let s = "hello";
    let mut c = || { println!("{:?}", s); };
    c();
    c();
    // c.call_mut(());
    // c.call_once(());
    c();
    println!("{:?}", s);
}
