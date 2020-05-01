//需要明确指定trait对象生命周期
trait Foo<'a> {}

struct FooImpl<'a> {
    s : &'a [u32],
}

impl<'a> Foo<'a> for FooImpl<'a> {

}

fn foo<'a>(s : &'a [u32]) -> Box<Foo<'a> + 'a> {
    Box::new(FooImpl{s : s})
}

fn main() {
    println!("Hello, world!");
}
