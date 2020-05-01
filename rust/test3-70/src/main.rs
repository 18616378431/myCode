//使用into方法简化代码
#[derive(Debug)]
struct Person {
    name : String,
}

impl Person {
    fn new<T : Into<String>>(name : T) -> Person {
        Person{name : name.into()}
    }
}

fn main() {
    let person = Person::new("Alex");
    let person = Person::new("Alex".to_string());
    println!("{:?}", person);
}
