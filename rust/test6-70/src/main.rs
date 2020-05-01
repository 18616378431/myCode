//使用可变迭代器iter_mut()
fn main() {
    let mut arr = [1, 2, 3, 4, 5];

    for i in arr.iter_mut() {
        *i += 1;
    }

    println!("{:?}", arr);
}
