//无歧义完全限定语法 FQSD
struct S(i32);

trait A {
    fn test(&self, i : i32);
}

trait B {
    fn test(&self, i : i32);
}

impl A for S {
    fn test(&self, i : i32) {
        println!("From A: {:?}", i);
    }
}

impl B for S {
    fn test(&self, i : i32) {
        println!("From B: {:?}", i);
    }
}

fn main() {
    let s = S(1);
    A::test(&s, 1);
    B::test(&s, 1);
    <S as A>::test(&s, 1);
    <S as B>::test(&s, 1);
}
