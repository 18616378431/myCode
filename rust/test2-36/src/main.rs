//元组结构体,使用点号进行索引访问
struct Color(i32, i32, i32);

fn main() {
    let color = Color(0, 1, 2);
    assert_eq!(color.0, 0);
    assert_eq!(color.1, 1);
    assert_eq!(color.2, 2);
}
