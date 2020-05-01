//共享所有权Rc<T> Weak<T>
use std::rc::Rc;

fn main() {
    let x = Rc::new(45);
    let y1 = x.clone();//增加强引用计数
    let y2 = x.clone();//增加强引用计数
    println!("{:?}", Rc::strong_count(&x));

    let w = Rc::downgrade(&x);//增加弱引用计数
    println!("{:?}", Rc::weak_count(&x));
    let y3 = &*x;//不增加引用计数
    println!("{}", 100 - *x);
}
