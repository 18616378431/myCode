//值表达式不能出现在位置上下文中
fn main() {
    let x = &temp();
    temp() = *x;
}

pub fn temp() -> i32 {
    return 1;
}
