// #[may_dangle]
#![feature(allocator_api, dropck_eyepatch)]

use std::fmt;
use std::alloc::{GlobalAlloc, System, Layout};
use std::ptr;
use std::mem;
use std::marker::PhantomData;

#[derive(Debug, Clone, Copy)]
enum State {
    InValid,
    Valid,
}

#[derive(Debug)]
struct Hello<T : fmt::Debug>(&'static str, T, State);

impl<T : fmt::Debug> Hello<T> {
    fn new(name : &'static str, t : T) -> Self {
        Hello(name, t, State::Valid)
    }
}

impl<T : fmt::Debug> Drop for Hello<T> {
    fn drop(&mut self) {
        println!("drop Hello({} {:?} {:?})", self.0, self.1, self.2);
        self.2 = State::InValid;
    }
}

struct WrapBox<T> {
    v : Box<T>,
}

impl<T> WrapBox<T> {
    fn new(t : T) -> Self {
        WrapBox{v : Box::new(t)}
    }
}

struct MyBox<T> {
    v : *const T,
}

impl<T> MyBox<T> {
    fn new(t : T) ->Self {
        unsafe {
            let p = System.alloc(Layout::array::<T>(1).unwrap());
            let p = p as *mut T;
            ptr::write(p, t);
            MyBox {v : p}
        }
    }
}

unsafe impl<#[may_dangle] T> Drop for MyBox<T> {
    fn drop(&mut self) {
        unsafe {
            ptr::read(self.v);
            let p = self.v as *mut _;
            System.dealloc(p, Layout::array::<T>(mem::align_of::<T>()).unwrap());
        }
    }
}

struct MyBox2<T> {
    v : *const T,
    _pd : PhantomData<T>,
}

impl<T> MyBox2<T> {
    fn new(t : T) ->Self {
        unsafe {
            let p = System.alloc(Layout::array::<T>(1).unwrap());
            let p = p as *mut T;
            ptr::write(p, t);
            MyBox2 {v : p, _pd : Default::default()}
        }
    }
}

unsafe impl<#[may_dangle] T> Drop for MyBox2<T> {
    fn drop(&mut self) {
        unsafe {
            ptr::read(self.v);
            let p = self.v as *mut _;
            System.dealloc(p, Layout::array::<T>(mem::align_of::<T>()).unwrap());
        }
    }
}

fn f3() {
    // let (y ,x);
    // let (x, y);
    let x;let y;
    x = Hello::new("x", 13);
    y = MyBox2::new(Hello::new("y", &x));
}

// fn f2() {
//     {
//         let (x1, y1);
//         x1 = Hello::new("x1", 13);
//         y1 = MyBox::new(Hello::new("y1", &x1));
//     }
//     {
//         // let (x2, y2);
//         let (y2, x2);
//         x2 = Hello::new("x2", 13);
//         y2 = MyBox::new(Hello::new("y2", &x2));
//     }
// }

// fn f1() {
//     let x;let y;
//     // let (x, y);
//     x = Hello::new("x", 13);
//     y = WrapBox::new(Hello::new("y", &x));
// }

fn main() {
    // f1();
    // f2();
    f3();
}
