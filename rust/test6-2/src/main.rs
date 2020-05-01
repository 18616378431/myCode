//按值传递会导致所有权转移或执行Copy
//按值传递参数使用mut关键字修饰,相当于声明了另一个变量v的可变绑定
fn modify(mut v : Vec<u32>) -> Vec<u32> {
    v.push(42);
    v
}
fn main() {
    let v = vec![1, 2, 3];
    let v = modify(v);
    println!("{:?}", v);
}
