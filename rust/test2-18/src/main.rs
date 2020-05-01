//使用while true循环示例
fn main() {
    let y = while_true(5);
    assert_eq!(y, 6);
}

fn while_true(x : i32) -> i32 {
    while true {
        return x + 1;
    }
}