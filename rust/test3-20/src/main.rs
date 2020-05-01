//编译期单态化的泛型函数

fn foo_1(x : i32) -> i32 {
    return x;
}

fn foo_2(x : &'static str) -> &'static str {
    return x;
}

fn main() {
    foo_1(1);
    foo_2("hello");
}
