//导出mod定义的宏
#[macro_use]
mod macros {
    macro_rules! X { 
        () => { Y!(); };
    }
    macro_rules! Y { 
        () => {};
    }
}
fn main() {
    X!();
}
