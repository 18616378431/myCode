//使用while true循环示例,错误修复
fn main() {
    let y = while_true(5);
    assert_eq!(y, 6);
}

fn while_true(x : i32) -> i32 {
    while true {
        return x + 1;
    }

    x
}