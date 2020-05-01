//RefCell运行时借用检查,多个可变借用将导致线程panic
use std::cell::RefCell;

fn main() {
    let x = RefCell::new(vec![1, 2, 3, 4]);
    let mut mut_v = x.borrow_mut();
    mut_v.push(5);

    println!("{:?}", mut_v);

    let mut mut_v2 = x.borrow_mut();
}
