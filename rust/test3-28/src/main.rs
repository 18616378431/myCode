//重载整数加法操作
use std::ops::Add;

impl Add<u64> for u32 {
    type Output = u64;
    fn add(self, other : u64) -> Self::Output {
        (self as u64) + other
    }
}


fn main() {
    let a = 1u32;
    let b = 2u64;
    assert_eq!(a + b, 3);
}
