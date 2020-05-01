//slice类型数组
//into_iter会转移所有权 self
//iter为不可变借用迭代器, &self
//iter_mut为可变借用迭代器,&mut self
fn main() {
    let arr = [1, 2, 3, 4, 5];

    for i in arr.iter() {
        println!("{:?}", i);
    }

    println!("{:?}", arr);
}
