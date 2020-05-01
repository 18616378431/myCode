//声明宏 macro_rules!
macro_rules! unless {
    ($arg:expr, $branch:expr) => (if !$arg {$branch};);
}

fn cmp(a : i32, b : i32) {
    unless!(a > b, {
        println!("{} < {}", a, b);
    });
}

fn main() {
    let (a, b) = (1, 2);
    cmp(a, b);
}
