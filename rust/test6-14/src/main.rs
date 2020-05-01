//函数指针
fn hello (){
    println!("hello function pointer");
}
fn main() {
    let fn_ptr : fn() = hello;
    println!("{:p}", fn_ptr);

    let other_fn = hello;//other_fn实际为fn() {...}函数类型,非函数指针
    // println!("{:p}", other_fn);
    hello();
    other_fn();
    fn_ptr();
    (fn_ptr)();
}
