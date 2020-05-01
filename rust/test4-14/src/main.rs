//drop-flag
//使用花括号构造显式作用域主动析构局部变量
fn main() {
    let mut v = vec![1, 2, 3];

    {
        v;
    };

    v.push(4);
}
