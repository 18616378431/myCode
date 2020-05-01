//联合体字节对齐
union U {
    f1 : u32,
    f2 : f32,
    f3 : f64,
}

fn main() {
    println!("{:?}", std::mem::size_of::<U>());
}
