//match引用时需要手动解引用
fn main() {
    let x = "hello".to_string();
    match &*x {
        "hello" => {println!("hello");},
        _ => ()
    }
}
