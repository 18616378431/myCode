//具有引用语义的Box<T>默认会移动
fn main() {
    let x = Box::new(5);
    let y = x;

    println!("{:?}", x);
}
