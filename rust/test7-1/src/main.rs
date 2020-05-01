//简单类型成员结构体实现Copy
#[derive(Debug, Clone, Copy)]
struct Book<'a> {
    name : &'a str,
    isbn : i32,
    version : i32,
}

fn main() {
    let book = Book {name : "Rust编程之道", isbn : 20181212, version : 1};
    let book2 = Book {version : 2, ..book};
    println!("{:?}", book);
    println!("{:?}", book2);
}
