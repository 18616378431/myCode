//过程宏 实现了自定义派生属性new,编译时为结构体foo实现new方法
#[derive(new)]
struct Foo;

fn main() {
    let x = Foo:new();
    assert_eq!(x, Foo);
}
