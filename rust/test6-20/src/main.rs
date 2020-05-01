//闭包
//闭包捕获外部环境变量规则
/// 1.复制语义 以不可变引用方式捕获
/// 2.移动语义 执行移动语义转移所有权
/// 3.可变绑定 包含修改操作,以可变引用捕获(&mut)

fn counter(i : i32) -> Box<Fn(i32) -> i32> {
    Box::new(move |n : i32| n + i)
}

fn main() {
    let f = counter(3);
    assert_eq!(4, f(1));
}
