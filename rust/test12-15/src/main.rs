//rust编译过程
//Tokens 词法分析-》语法分析-》抽象语法树-》HIR-》MIR-》LLVM-IR-》Machine Code
fn t (i : i32) -> i32 {
    i + 2
}

fn main() {
    t(1);
}
