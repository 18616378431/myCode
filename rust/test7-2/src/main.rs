//移动语义成员
// #[derive(Debug, Copy, Clone)]
#[derive(Debug)]
struct Book {
    name : String,
    isbn : i32,
    version : i32,
}

fn main() {
    let book = Book {name : "Rust编程之道".to_string(), isbn : 20171111, version : 1};
    let book2 = Book {version : 2, ..book};
    println!("{:?}", book);
    println!("{:?}", book2);
}
