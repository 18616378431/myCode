//生成器 feature
#![feature(generators, generator_trait)]
use std::ops::{Generator, GeneratorState};

fn up_to(limit : u64) -> impl Generator<Yield = (), Return = Result<u64, ()>> {
    move || {
        for x in 0..10 {
            yield ();
        }
        Ok(limit)
    }
}

fn main() {
    let limit = 2;
    let mut gen = up_to(limit);
    unsafe {
        for i in 0..=limit {
            match gen.resume() {
                GeneratorState::Yielded(v) => println!("resume {:?} : Pending", i),
                GeneratorState::Complete(v) => println!("resume {:?} : Ready", i),
            }
        }
    }
}
