//对象不安全的trait
trait Foo {
    fn bad<T>(&self, x : T);
    fn new() -> Self;
}

//将对象不安全的泛型方法拆分为独立的trait
trait Bar {
    fn bad<T>(&self, x : T);
}

//Foo就成为了对象安全的trait
trait Foo :Bar {
    fn new() -> Self;
}

//对象安全的trait,使用where子句
trait Foo {
    fn new() -> Self where Self : Sized;
}

fn main() {
    println!("Hello, world!");
}
