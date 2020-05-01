//闭包
fn main() {
    // let add = |a : i32, b : i32| -> i32 { a + b };
    let add = |a, b| -> i32 { a + b };
    // let add = |a, b| a + b;
    assert_eq!(3, add(1, 2));

    let (a, b) = (1, 2);
    let add = || a + b;

    println!("{:?}", add());
}
