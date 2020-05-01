//逆变 fn(T)
trait A {
    fn foo(&self, s : &'static str);
}

struct B;

impl A for B {
    fn foo(&self, s: &str) {
        println!("{:?}", s);
    }
}

impl B {
    fn foo2(&self, s : &'static str) {
        println!("{:?}", s);
    }
}

fn main() {
    B.foo("hello");
    let s = "hello".to_string();
    B.foo2(&s);
}
