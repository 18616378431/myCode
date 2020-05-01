//bool类型示例
fn main() {
    let x = true;
    
    assert_eq!(x as i32, 1);
    
    let y : bool  = false;
    let x = 5;
    
    if x > 1 {
        println!("x is bigger than 1");
    }

    assert_eq!(y as i32, 0);
}