//自动解引用Deref
fn main() {
    let a = "hello".to_string();
    let b = " world".to_string();
    let c = a + &b;
    
    println!("{:?}", c);
}
