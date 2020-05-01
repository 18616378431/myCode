//枚举体
enum Number {
    Zero,
    One,
    Two,
}
fn main() {
    let a = Number::One;

    match a {
        Number::Zero => println!("0"),
        Number::One => println!("1"),
        Number::Two => println!("2")
    }
}
