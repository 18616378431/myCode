//移动语义类型自动实现FnOnce 转移所有权 消耗闭包自身及移动语义环境变量
// #![feature(fn_traits)]

fn main() {
    let s = "hello".to_string();
    let c = || s;
    c();
    // c.call(());
    // c.call_mut(());
    // c();
    // println!("{:?}", s);
}
