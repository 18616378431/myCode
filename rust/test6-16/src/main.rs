//高阶函数 使用type关键字定义函数指针类型别名
//函数做为返回值
type MathOp = fn(i32, i32) -> i32;
fn math(op : &str) -> MathOp {
    fn sum(a : i32, b : i32) -> i32 {
        a + b
    }
    
    fn product(a : i32, b : i32) -> i32 {
        a * b
    }

    match op {
        "sum" => sum,
        "product" => product,
        _ => {
            println!("Warning:Not implemented {:?} operator,Replace with sum", op);
            sum
        }
    }
}



fn main() {
    let (a, b) = (2, 3);
    let sum = math("sum");
    let product = math("product");
    let div = math("div");

    assert_eq!(sum(a, b), 5);
    assert_eq!(product(a, b), 6);
    assert_eq!(div(a, b), 5);
}
