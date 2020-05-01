//move关键字对闭包所有权的影响
/// FnMut在使用move时
/// 1.如果捕获变量是复制语义,则闭包会实现Copy/Clone
/// 2.如果捕获变量是移动语义,则不会实现Copy/Clone
fn call<F : FnOnce()>(f : F) {
    f();
}

fn main() {
    //未使用move
    let mut x = 0;
    let incr_x = || x += 1;
    call(incr_x);
    // call(incr_x);
    
    //使用move
    let mut x = 0;
    let incr_x = move || x += 1;
    call(incr_x);
    call(incr_x);

    //对移动语义类型使用move
    let mut x = vec![];
    let expend_x = move || x.push(42);
    call(expend_x);
    // call(expend_x);
}
