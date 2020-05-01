//函数做为返回值的情况
fn main() {
    assert_eq!(true_maker()(), true);
}


fn is_true() -> bool {
    true
}

fn true_maker() -> fn() -> bool {
    is_true
}