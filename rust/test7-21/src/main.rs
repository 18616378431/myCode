//析构顺序 本地变量
struct PrintDrop(&'static str);

impl Drop for PrintDrop {
    fn drop(&mut self) {
        println!("Dropping {}", self.0);
    }
}

fn main() {
    let a = PrintDrop("1");
    let b = PrintDrop("2");
    let c = PrintDrop("3");
}
