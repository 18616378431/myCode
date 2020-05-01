//通过as操作符抓换类型和子类型
fn main() {
    let a : &'static str = "hello";
    let b : &str = a as &str;
    let c : &'static str = b as &'static str;
}
