//一个元素的元组结构体叫做new type
//type关键字可以定义新的类型,新的类型与原来类型具有相同属性
struct Integer(u32);

type Int = i32;

fn main() {
    let int = Integer(10);
    assert_eq!(int.0, 10);

    let int : Int = 10;
    assert_eq!(int, 10);
}
