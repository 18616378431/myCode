//引用移动语义做为函数参数
fn foo(s : String) -> String {
    let w = " world".to_string();
    s + &w
}

fn main() {
    let s = "hello".to_string();
    let ss = foo(s);

    println!("{:?}", s);//s做为函数参数发生了所有权转移
}
