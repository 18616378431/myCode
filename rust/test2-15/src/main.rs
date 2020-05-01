//闭包做为返回值的情况
fn main() {
    let result = two_times_impl();
    assert_eq!(result(2), 4);
}

fn two_times_impl() -> impl Fn(i32) -> i32 {
    let i = 2;
    move |j| j * i
}
