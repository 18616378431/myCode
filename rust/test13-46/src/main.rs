//自定义全局分配器
use std::alloc::{GlobalAlloc, System, Layout};

struct MyAllocator;

unsafe impl GlobalAlloc for MyAllocator {
    unsafe fn alloc(&self, layout : Layout) -> *mut u8 {
        System.alloc(layout)
    }

    unsafe fn dealloc(&self, ptr : *mut u8, layout : Layout) {
        System.dealloc(ptr, layout);
    }
}

#[global_allocator]
static GLOBAL : MyAllocator = MyAllocator;

//使用jemalloc
// extern crate jemallocator;
// use jemallocator::Jemalloc;
// #[global_allocator]
// static GLOBAL : Jemalloc = Jemalloc;

fn main() {
    //使用自定义内存分配器分配vec内存
    let mut v = Vec::new();
    v.push(1);
}
