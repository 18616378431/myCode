//当元素均为复制语义类型时,元组自动实现Copy trait
fn main() {
    let a = ("a".to_string(), "b".to_string());
    let b = a;//moved
    // println!("{:?}", a);

    let c = (1, 2, 3);
    let d = c;
    println!("{:?}", c);
}
