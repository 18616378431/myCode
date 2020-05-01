//闭包做为参数的情况
fn main() {
    let a = 2;
    let b = 3;
    assert_eq!(math(|| a + b), 5);
    assert_eq!(math(|| a * b), 6);
}

fn math<F : Fn() -> i32>(op : F) -> i32 {
    op()
}
