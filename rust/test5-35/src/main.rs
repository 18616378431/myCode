//结构体中的引用成员标注生命周期参数
struct Foo<'a> {
    part : &'a str,
}
fn main() {
    let words = String::from("Sometimes think,the greatest sorrow than older");
    let first = words.split(',').next().expect("Could not find a ','");
    let f = Foo {part : first};
    assert_eq!("Sometimes think", f.part);
}
