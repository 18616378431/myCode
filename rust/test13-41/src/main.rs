//NonNull 内置方法
use std::ptr::{null, NonNull};

fn main() {
    let ptr : NonNull<i32> = NonNull::dangling();//悬垂指针
    println!("{:p}", ptr);
    let mut v = 42;
    let ptr : Option<NonNull<i32>> = NonNull::new(&mut v);
    println!("{:?}", ptr);
    println!("{:?}", ptr.unwrap().as_ptr());
    println!("{:?}", unsafe { ptr.unwrap().as_mut() });
    let mut v = 42;
    let ptr = NonNull::from(&mut v);
    println!("{:?}", ptr);
    let null_p : *const i32 = null();
    let ptr = NonNull::new(null_p as *mut i32);
    println!("{:?}", ptr);
}
