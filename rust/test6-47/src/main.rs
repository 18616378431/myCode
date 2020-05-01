//返回闭包必须做为trait对象
fn square() -> Box<Fn(i32) -> i32> {
    Box::new(|i| i * i)
}

fn main() {
    let square = square();
    assert_eq!(4, square(2));
    assert_eq!(9, square(3));
}
