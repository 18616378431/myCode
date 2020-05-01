//函数的输入引用参数和返回引用生命周期毫无关联,生命周期参数无效
fn foo<'a>(a : &'a str, y : &'a str) -> &'a str {
    let result = String::from("really long string");
    result.as_str()
}
fn main() {
    let x = "hello";
    let y = "rust";
    foo(x, y);
}
