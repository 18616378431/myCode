//空指针优化
use std::mem;
use std::ptr::NonNull;

struct Foo {
    a : *mut u64,
    b : *mut u64,
}

struct FooUsingNoNull {
    a : *mut u64,
    b : NonNull<*mut u64>,
}

fn main() {
    println!("*mut u64 : {} bytes", mem::size_of::<*mut u64>());
    println!("NonNull<*mut u64> : {} bytes", mem::size_of::<NonNull<*mut u64>>());

    println!("Option<*mut u64> : {} bytes", mem::size_of::<Option<*mut u64>>());
    println!("Option<NonNull<*mut u64>> : {} bytes", mem::size_of::<Option<NonNull<*mut u64>>>());

    println!("Option<Foo> : {} bytes", mem::size_of::<Option<Foo>>());
    println!("Option<FooUsingNoNull>  : {} bytes", mem::size_of::<Option<FooUsingNoNull>>());
}
