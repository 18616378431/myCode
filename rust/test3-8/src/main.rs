//使用Vec<()>迭代类型
fn main() {
    let v : Vec<()> = vec![(); 10];

    for i in v {
        println!("{:?}", i);
    }
}
