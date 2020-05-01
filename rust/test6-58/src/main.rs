//for循环展开等价代码
fn main() {
    let v = vec![1, 2, 3, 4, 5];

    {//等价for循环的scope
        let mut _iterator = v.into_iter();
        loop {
            match _iterator.next() {
                Some(i) => {
                    println!("{:?}", i);
                },
                None => break,
            }
        }
    }
}
