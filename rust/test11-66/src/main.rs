//生成器与迭代器
#![feature(generators, generator_trait)]
use std::ops::{Generator, GeneratorState};

fn up_to() -> impl Generator<Yield = u64, Return = ()> {
    || {
        let mut x = 0;
        loop {
            x += 1;
            yield x;
        }
        return ();
    }
}

fn main() {
    let mut gen = up_to();
    unsafe {
        for _ in 0..10 {
            match gen.resume() {
                GeneratorState::Yielded(i) => println!("{:?}", i),
                _ => println!("Completed"),
            }
        }
    }
}
