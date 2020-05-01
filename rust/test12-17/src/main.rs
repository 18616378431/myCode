//抽象语法树AST
fn main() {
    let (a, b, c, d, e) = (1, 2, 3, [4, 5], 6);
    a + b + (c + d[0]) + e;
}
