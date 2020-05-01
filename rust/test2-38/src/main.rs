//单元结构体
//单元结构体的对象在debug模式下具有不同的内存地址
//在release模式下具有相同的内存地址,被优化为了同一个对象
struct Empty;

fn main() {
    let x = Empty;
    println!("{:p}", &x);

    let y = x;
    println!("{:p}", &y);

    let z = Empty;
    println!("{:p}", &z);

    assert_eq!((..), std::ops::RangeFull);
}
