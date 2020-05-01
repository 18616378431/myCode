//指定增长值得函数
fn counter(i : i32) -> fn(i32) -> i32 {
    //counter函数参数i会随着函数栈帧的释放而释放
    fn inc(n : i32) -> i32 {
        n + i
    }
    inc
}

fn main() {
    let f = counter(2);
    assert_eq!(3, f(1));
}
