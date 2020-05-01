//par_iter par_iter_mut join
extern crate rayon;
use rayon::prelude::*;

fn fib(n : u32) -> u32 {
    if n < 2 {
        return n;
    }

    let (a, b) = rayon::join(|| fib(n - 1), || fib(n - 2));
    a + b
}

fn main() {
    let r = fib(32);
    assert_eq!(r, 2178309);    
}
