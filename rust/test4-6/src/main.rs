//检测循环中是否产生未初始化变量
fn main() {
    let x : i32;
    let mut y = 0;

    loop {
        y += 1;

        if y > 3 {
            x = 2;
            break;
        }
    }

    println!("{:?}", x);//2
}
