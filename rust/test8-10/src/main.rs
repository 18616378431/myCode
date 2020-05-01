//split_at split_at_mut
fn main() {
    let s = "bor道oos";
    let (first, last) = s.split_at(3);
    assert_eq!("bor", first);
    assert_eq!("道oos", last);
    // let (first, last) = s.split_at(4);

    println!("{:?}", &s[3..=5]);
}
