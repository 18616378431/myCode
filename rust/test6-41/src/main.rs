//闭包做为trait对象
fn boxed_closure(c : &mut Vec<Box<Fn()>>) {
    let s = "second";
    c.push(Box::new(|| println!("first")));
    c.push(Box::new(move || println!("{}", s)));
    c.push(Box::new(|| println!("third")));
}
fn main() {
    let mut c : Vec<Box<Fn()>> = vec![];
    boxed_closure(&mut c);

    for f in c {
        f();
    }
}
