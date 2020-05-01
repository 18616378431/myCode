//unsafe
/// unsafe块中的safe rust依然进行安全检查
/// unsafe在以下五种情况下不进行任何安全检查
/// [1]解引用操作
/// [2]调用unsafe函数或方法
/// [3]访问或修改可变静态变量
/// [4]实现unsafe trait
/// [5]读写Union联合体中的字段
fn main() {
    unsafe {
        let mut a = "hello";
        let b = &a;
        let c = &mut a;
    }
}
