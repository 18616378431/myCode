//解析字符串错误处理
use std::num::ParseIntError;

fn square(number_str : &str) -> Result<i32, ParseIntError> {
    number_str.parse::<i32>().map(|n| n.pow(2))
}

//使用type关键字为类型定义别名
type ParseResult<T> = Result<T, ParseIntError>;
fn square_type(number_str : &str) -> ParseResult<i32> {
    number_str.parse::<i32>().map(|n| n.pow(2))
}

fn main() {
    match square("10") {
        Ok(n) => assert_eq!(n, 100),
        Err(err) => println!("Error : {:?}", err),
    }

    println!("{:?}", square_type("20"));

}
