//trait包含默认实现的的特化示例
// #![feature(specialization)]
struct Diver<T> {
    inner : T,
}

trait Swimmer {
    // fn swim(&self) {
    //     println!("swimming");
    // }
    fn swim(&self);
}

// impl<T> Swimmer for Diver<T> {}

// impl Swimmer for Diver<&'static str> {
impl<T> Swimmer for Diver<T> {
    default fn swim(&self) {
        println!("drowning,help");
    }
}

fn main() {
    let x = Diver::<&'static str> {inner : "Bob"};
    x.swim();
    let y = Diver::<String> {inner : String::from("Alice")};
    y.swim();
}
