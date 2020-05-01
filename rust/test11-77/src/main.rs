//async/await
#![feature(arbitrary_self_types, futures_api)]
#![feature(async_await, await_macro, pin)]

use futures::{
    executor::ThreadPool,
    task::SpawnExt,
};
use std::future::Future;
use std::pin::Pin;
use std::task::*;

pub struct AlmostReady {
    ready : bool,
    value : i32,
}

pub fn almost_ready(value : i32) -> AlmostReady {
    AlmostReady {ready : false, value}
}

impl Future for AlmostReady {
    type Output = i32;
    fn poll(self : Pin<&mut Self>, lw : &LocalWaker) -> Poll<Self::Output> {
        if self.ready {
            Poll::Ready(self.value + 1)
        } else {
            unsafe {
                Pin::get_mut_unchecked(self).ready = true;
                lw.wake();
                Poll::Pending
            }
        }
    }
}

fn main() {
    let mut executor = ThreadPool::new().unwrap();
    let future = async {
        println!("howdy!");
        let x = await!(almost_ready(5));
        println!("done : {:?}", x);
    };
    executor.run(future);
}
