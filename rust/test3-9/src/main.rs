//底类型应用
fn main() {
    let i = if false {
        foo();
    } else {
        100
    };

    assert_eq!(i, 100);
}

#[feature(never_type)]
fn foo() -> ! {
    loop {
        println!("jh");
    }
}