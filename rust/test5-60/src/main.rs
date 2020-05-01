//非词法作用域生命周期
//变量定义顺序导致的生命周期问题
//先定义后析构
fn foo<'a>(x : &'a str, y : &'a str) -> &'a str {
    if x.len() % 2 == 0 {
        x
    } else {
        y
    }
}

fn main() {
    let x = String::from("hello");
    let z;
    let y = String::from("world");
    z = foo(&x, &y);
    //z借用了y,但y先析构,导致z悬垂引用
    println!("{:?}", z);    
}
