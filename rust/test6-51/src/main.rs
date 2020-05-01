//impl trait,可以直接返回FnOnce trait
fn square() -> impl FnOnce(i32) -> i32 {
    |i| i * i
}

fn main() {
    let square = square();
    assert_eq!(4, square(2));
}
