//rev反向遍历
fn main() {
    let arr = [1, 2, 3];
    let mut iter = arr.iter().rev();
    assert_eq!(iter.next(), Some(&3));
    assert_eq!(iter.next(), Some(&2));
    assert_eq!(iter.next(), Some(&1));
    assert_eq!(iter.next(), None);
}
