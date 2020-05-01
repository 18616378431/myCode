//match匹配产生新的词法作用域
fn main() {
    let a = Some("hello".to_string());
    
    match a {//match scope
        Some(s) => println!("{:?}", s),
        //match内部每个匹配分支都是独立的词法作用域
        _ => println!("nothing"),
    }

    //a是Option<String>类型,为移动语义,在match处发生了所有权转移
    // println!("{:?}", a);
}
