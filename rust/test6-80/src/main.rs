//迭代消费器 
//any 判断容器中是否存在指定的值
//fold 累加容器中的值返回sum
//collect 将消耗迭代器转换为指定的类型
fn main() {
    let a = [1, 2, 3];
    assert_eq!(a.iter().any(|&x| x != 2), true);
    let sum = a.iter().fold(0, |acc, x| acc + x);
    assert_eq!(6, sum);
}
