//Rc内部不可变,使用RefCell保证编译期不可变,运行期可变
use std::cell::RefCell;
use std::rc::Rc;
use std::ops::Drop;

type NodePtr<T> = Option<Rc<RefCell<Node<T>>>>;

struct Node<T> {
    data : T,
    next : NodePtr<T>,
}

//检测内存是否可以被正确释放实现Drop trait
impl<T> Drop for Node<T> {
    fn drop(&mut self) {
        println!("Dropping!");
    }
}

fn main() {
    let first = Rc::new(RefCell::new(Node {
        data : 1,
        next : None,
    }));

    let second = Rc::new(RefCell::new(Node {
        data : 2,
        next : Some(first.clone()),
    }));

    first.borrow_mut().next = Some(second.clone());
    second.borrow_mut().next = Some(first.clone());
}
