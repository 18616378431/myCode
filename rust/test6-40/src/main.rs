//未捕获环境变量的闭包会自动实现Fn
//可调用多次,&self
fn main() {
    let c = || { println!("hhh"); };
    c();
    c();
}
