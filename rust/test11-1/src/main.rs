//多线程并发问题
static mut V : i32 = 0;
/// 1.从内存读取 放入寄存器
/// 2.将寄存器中的数据+1
/// 3.将+1后的值写入内存
/// 
/// 由于多线程的执行顺序取决于内核调度
/// 执行顺序无法预测

//rust不允许修改静态变量的值 需要放到unsafe块中
fn unsafe_sq() -> i32 {
    unsafe {
        V += 1;
        V
    }
}

fn main() {
    println!("Hello, world!");
}
