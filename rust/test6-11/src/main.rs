//turbofish操作符执行泛型参数类型::<>
use std::ops::Mul;

fn square<T : Mul<Output = T>>(x : T, y : T) -> T {
    x * y
}

fn main() {
    let a = square::<u32>(37, 41);
    let b = square::<f32>(37.2, 41.1);
    assert_eq!(a, 1517);
    assert_eq!(b, 1528.9199);
}
