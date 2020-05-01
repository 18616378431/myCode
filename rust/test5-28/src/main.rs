//生命周期参数
fn main() {
    let r;//'a
    {
        let x = 5;
        r = &x;//'b
    }
    println!("{:?}", r);
}
