//检测分支流程是否产生未初始化变量
fn main() {
    let x : i32;

    if true {
        x = 1;
    }
    // } else {
    //     x = 2;
    // }

    // println!("{:?}", x);
}
