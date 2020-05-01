//将已初始化变量绑定给另一个变量
//所有权转移产生了未初始化变量
fn main() {
    let x = 42;
    let y = Box::new(5);
    println!("{:p}", y);

    let x2 = x;
    let y2 = y;
    // println!("{:p}", y);
}
