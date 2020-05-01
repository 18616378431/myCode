//fold
fn main() {
    let arr = vec![1, 2, 3];
    let sum1 = arr.iter().fold(0, |acc, x| acc + x);
    let sum2 = arr.iter().fold(0, |acc, x| acc + *x);
    let sum3 = arr.iter().fold(0, |acc, &x| acc + x);
    let sum4 = arr.iter().fold(0, |acc, x| acc + x);

    assert_eq!(6, sum1);
    assert_eq!(6, sum2);
    assert_eq!(6, sum3);
    assert_eq!(6, sum4);
}
