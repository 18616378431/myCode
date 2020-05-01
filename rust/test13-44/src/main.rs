//unsafe与线程恐慌
struct A(u32);

impl Drop for A {
    fn drop(&mut self) {
        println!("droping {} in A", self.0);
    }
}

unsafe fn panic_unsafe(x : &mut Vec<A>, a : A) {
    x.reserve(10);
    x.push(a);
    x.set_len(10);
    panic!("panic in unsafe block");
}

fn main() {
    let mut x = vec![];
    unsafe {
        panic_unsafe(&mut x, A(42));
    }
}
