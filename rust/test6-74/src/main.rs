//其他迭代器
/// map
/// filter_map
/// enumerate
/// rev
/// filter
/// chain
/// cloned
/// flatmap
/// fuse
/// cycle
fn main() {
    //map
    let arr1 = [1, 2, 3, 4, 5];
    let c1 = arr1.iter().map(|x| x * 2).collect::<Vec<i32>>();
    assert_eq!(&c1[..], [2, 4, 6, 8, 10]);

    //filtermap
    let arr2 = ["1", "2", "3", "h"];
    let c2 = arr2.iter().filter_map(|x| x.parse().ok()).collect::<Vec<i32>>();
    assert_eq!(&c2[..], [1, 2, 3]);

    //enumerate
    let arr3 = ['a', 'b', 'c'];
    for (idx, val) in arr3.iter().enumerate() {
        println!("id : {:?}, val : {:?}", idx, val.to_uppercase());
    }
}
