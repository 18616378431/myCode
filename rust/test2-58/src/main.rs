//注释示例

/// 文档注释:Sum函数
/// 该函数为求和函数
/// usage:
/// assert_eq!(3, sum(1, 2));
fn sum(a : i32, b : i32) -> i32 {
    a + b
}

fn main() {
    //单行注释示例

    /**
     * 区块注释 可以放置在代码中的任何位置
     */

     /*
        仅开头结尾需要*
     */

    let x = 5 + /* 90 + */ 5;
    assert_eq!(x, 10);
    println!("2 + 3 = {}", sum(2, 3));

    
}

/**
 * println! 格式说明符
 * nothing 代表 Display
 * ? Debug
 * o 八进制
 * x 小写十六进制
 * X 大写十六进制
 * p 指针地址
 * b 二进制
 * e 指数小写
 * E 指数大写
 */
