//函数做为返回值,并与参与计算的值进行绑定
fn sum(a : i32, b : i32) -> i32 {
    a + b
}

fn product(a : i32, b : i32) -> i32 {
    a * b
}

type MathOp = fn(i32, i32) -> i32;
fn math(op : &str, a : i32, b : i32) -> MathOp {
    match op {
        "sum" => sum(a, b),
        _ => product(a, b)
    }
}

fn main() {
    println!("Hello, world!");
}
