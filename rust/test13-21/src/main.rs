//未绑定生命周期 原生指针转换为引用
fn foo<'a>(input : *const u32) -> &'a u32 {
    unsafe {
        return &*input;
    }
}

fn main() {
    let x;
    {
        let y = 42;
        x = foo(&y);
    }
    println!("Hello : {}", x);
}
