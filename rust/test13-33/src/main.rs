//std::mem::forget
use std::mem;

struct A;

struct B;

struct Foo {
    a : A,
    b : B,
}

impl Foo {
    fn take(mut self) -> (A, B) {
        let a = mem::replace(&mut self.a, unsafe {mem::uninitialized()});
        let b = mem::replace(&mut self.b, unsafe {mem::uninitialized()});
        mem::forget(self);
        (a, b)
    }
}

impl Drop for Foo {
    fn drop(&mut self) {

    }
}

fn main() {
    println!("Hello, world!");
}
