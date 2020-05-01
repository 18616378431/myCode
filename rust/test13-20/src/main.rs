//逆变 将来可能取消逆变fn(T)
fn foo(input : &str) {
    println!("{:?}", input);
}

fn bar(f : fn(&'static str), v : &'static str) {
    (f)(v);
}

fn main() {
    let v : &'static str = "hello";
    bar(foo, v);
}
