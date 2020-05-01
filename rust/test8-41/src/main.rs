//Vector堆内存预分配
fn main() {
    let mut vec = Vec::with_capacity(10);
    for i in 0..10 {
        vec.push(i);
    }
    vec.truncate(0);
    assert_eq!(vec.capacity(), 10);
    for i in 0..10 {
        vec.push(i);
    }
    vec.clear();
    assert_eq!(vec.capacity(), 10);
    vec.shrink_to_fit();
    assert_eq!(vec.capacity(), 0);
    for i in 0..10 {
        vec.push(i);
        println!("{:?}/", vec.capacity());
    }
}
