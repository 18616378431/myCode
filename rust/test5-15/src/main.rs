//for循环语句创建的新的词法作用域
//for循环中,v的所有权发生了转移
fn main() {
    let v = vec![1, 2, 3];

    for i in v {
        println!("{:?}", i);
        println!("{:?}", v);
    }
}
