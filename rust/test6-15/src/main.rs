//高阶函数 使用type关键字定义函数指针类型别名
type MathOp = fn(i32, i32) -> i32;
fn math(op : MathOp,a : i32, b : i32) -> i32 {
    op(a, b)
}

fn sum(a : i32, b : i32) -> i32 {
    a + b
}

fn product(a : i32, b : i32) -> i32 {
    a * b
}

fn main() {
    let (a, b) = (2, 3);
    assert_eq!(math(sum, a, b), 5);
    assert_eq!(math(product, a, b), 6);
}
