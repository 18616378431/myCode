//结构体对齐
//Rust中编译期会对结构体进行重排,以减少空间浪费
//b,c,a
struct A {
    a : u8,
    b : u32,
    c : u16,
}

fn main() {
    println!("{:?}", std::mem::size_of::<A>());//8
}
