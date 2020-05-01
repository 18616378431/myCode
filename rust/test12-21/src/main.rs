//声明宏cargo rustc -- -Z unstable-options --pretty=expanded
macro_rules! unless {
    ($arg:expr, $branch:expr) => (if !$arg { $branch };);
}

fn main() {
    let (a, b) = (1, 2);
    unless!(a > b, {
        b - a;
    })
}
