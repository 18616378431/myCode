//Vector存储0大小类型
struct Foo;

fn main() {
    let mut vec = Vec::new();
    vec.push(Foo);
    assert_eq!(vec.capacity(), std::usize::MAX);
}
