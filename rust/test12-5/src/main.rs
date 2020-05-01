//downcast_ref downcast_mut 将泛型向下转换为不可变借用和可变借用
use std::any::Any;

#[derive(Debug)]
enum E {
    H,
    He,
    Li,
}

struct S {
    x : u8,
    y : u8,
    z : u16,
}

//Any为trait对象
fn print_any(a : &Any) {
    if let Some(v) = a.downcast_ref::<u32>() {
        println!("u32 {:x}", v);
    } else if let Some(v) = a.downcast_ref::<E>() {
        println!("E : {:?}", v);
    } else if let Some(v) = a.downcast_ref::<S>() {
        println!("struct S : {:x} {:x} {:x}", v.x, v.y, v.z);
    } else {
        println!("else!");
    }
}

fn main() {
    print_any(& 0xc0ffee_u32);
    print_any(& E::He);
    print_any(& S {x : 0xde, y : 0xad, z : 0xbeef});
    print_any(& "rust");
    print_any(& "hoge");
}
