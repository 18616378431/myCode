//使用元组让函数返回多个值
fn addsub(x : isize, y : isize) -> (isize, isize) {
    (x + y, x - y)
}

fn main() {
    let (a, b) = addsub(5, 8);
    println!("a: {:?}, b : {:?}", a, b);    
}
