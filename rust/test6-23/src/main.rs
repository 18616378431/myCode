//定义相同的闭包不属于同一种类型
fn main() {
    let c1 = || {};
    let c2 = || {};
    let v = vec![c1, c2];
}
