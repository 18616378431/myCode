//对移动语义进行解引用会导致所有权转移
fn join(s : &String) -> String {
    let append = *s;
    "Hello".to_string() + &append
}

fn main() {
    let x = " hello".to_string();
    join(&x);
}
