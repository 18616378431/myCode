//解引用智能指针
fn main() {
    let a = Box::new("hello");
    let b = Box::new("Rust".to_string());
    let c = *a;//a装箱的是字符串字面量,具有复制语义,按位复制
    let d = *b;//b装箱的是String类型,具有引用语义,解引用导致所有权转移

    println!("{:?}", a);
    println!("{:?}", b);
}
