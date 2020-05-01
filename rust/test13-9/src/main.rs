//访问联合体中未初始化的字段
#[repr(C)]
union U {
    i : i32,
    f : f32,
}

fn main() {
    let u = U{i : 1};
    let i = unsafe {
        u.f
    };
    println!("{}", i);//f32::from_bits(1);

    // unsafe {
    //     let i = &mut u.i;
    //     let f = &mut u.f;
    // };
}
