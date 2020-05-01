//智能指针与所有权
//智能指针Box<T>独占所有权
fn main() {
    let x = Box::new("hello");
    let y = x;//所有权转移
    println!("{:?}", x);
}
