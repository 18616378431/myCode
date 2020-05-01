//闭包
//可以像匿名函数一样被调用
//可以捕获上下文环境中的自由变量
//可以自动推断输入和返回的类型
fn main() {
    let out = 42;
    // fn add(i : i32, j : i32) -> i32 {i + j + out}
    fn add(i : i32, j : i32) -> i32 {i + j}
    let closure_annotated = |i : i32, j : i32| -> i32 {i + j + out};
    let closure_inferred = |i, j| i + j + out;

    let i = 1;
    let j = 2;

    assert_eq!(3, add(i,j));
    assert_eq!(45, closure_annotated(i, j));
    assert_eq!(45, closure_inferred(i, j));
}
