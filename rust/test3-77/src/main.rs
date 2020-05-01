//代码复用率
//重叠规则
use std::ops::Add;

impl<R, T : Add<R> + Clone> AddAssign<R> for T {
    fn add_assign(&mut self,rhs : R) {
        let tmp = self.clone() + rhs;
        *self = tmp;
    }
}
fn main() {
    println!("Hello, world!");
}
