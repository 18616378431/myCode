//实现了FnMut闭包的情况
// #![feature(fn_traits)]
fn main() {
    let mut s = "rush".to_string();
    {
        let mut c = || s += " rust";
        c();
        // c.call(());
        // c.call_once(());
        println!("{:?}", s);
    }
    println!("{:?}", s);
}
