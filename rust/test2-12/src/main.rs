//CTFE Compile-Time Function Execution,编译期函数执行
//函数值必须确定
fn main() {
    let arr = [0;init_len()];
}

// #![feature(const_fn)]
const fn init_len() -> usize {
    return 5;
}
