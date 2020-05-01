//any
fn main() {
    let arr = [1, 2, 3];
    let result1 = arr.iter().any(|&x| x != 2);
    let result2 = arr.iter().any(|x| *x != 2);
    // let result2 = arr.iter().any(|x| x != 2);//x为借用 无法比较

    assert_eq!(result1, true);
    assert_eq!(result2, true);
}
