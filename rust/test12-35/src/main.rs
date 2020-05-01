//声明宏的卫生性
macro_rules! sum {
    ($e:expr) => ({
        let a = 2;
        $e + a
    });
}
fn main() {
    let four = sum!(a);
}
