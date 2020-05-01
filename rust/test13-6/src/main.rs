//访问或修改可变静态变量时不进行任何安全检查
static mut COUNTER : u32 = 0;
fn main() {
    let inc = 3;
    unsafe {
        COUNTER += inc;
        println!("COUNTER : {}", COUNTER);
    }
    // COUNTER += inc;
    // println!("COUNTER : {}", COUNTER);

}
