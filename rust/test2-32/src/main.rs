//never类型示例
fn main() {
    let num : Option<u32> = Some(42);

    match num {
        Some(num) => num,
        None => panic!("Nothing"),
    };
}

// #![feature(never_type)]
fn foo() -> u32 {
    let x : ! = {
        return 123
    };
}
