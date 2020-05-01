//线程恐慌assert! assert_eq! assert_ne! debug_assert! debug_assert_eq! debug_assert_ne!
fn main() {
    let x = false;
    // assert!(x, "x wasn't true!");
    let a = 3;
    let b = 28;
    debug_assert!(a + b == 30, "a = {}, b = {}", a, b);
}
