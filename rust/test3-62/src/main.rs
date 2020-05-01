//手动解引用
use std::rc::Rc;

fn main() {
    let x = Rc::new("hello");
    let y = x.clone();//Rc<&str>
    let z = (*x).clone();//&str
}
