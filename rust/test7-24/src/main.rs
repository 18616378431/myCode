//元组析构顺序
struct PrintDrop(&'static str);

impl Drop for PrintDrop {
    fn drop(&mut self) {
        println!("{}", self.0);
    }
}

enum E {
    Foo(PrintDrop, PrintDrop)
}

struct Foo {
    x : PrintDrop,
    y : PrintDrop,
    z : PrintDrop,
}

fn main() {
    // let tup1 = (PrintDrop("a"),PrintDrop("b"),PrintDrop("c"));
    // let tup2 = (PrintDrop("x"),PrintDrop("y"),PrintDrop("z"));

    //panic!提前析构 元组内反向析构 
    //正常会先进后出,元组内部按出现顺序进行析构
    // let tup2 = (PrintDrop("x"),PrintDrop("y"), panic!());

    //结构体 枚举体析构顺序 clice 和元组一致
    // let e = E::Foo(PrintDrop("a"), PrintDrop("b"));
    // let f = Foo {
    //     x : PrintDrop("x"),
    //     y : PrintDrop("y"),
    //     z : PrintDrop("z"),
    // };

    //闭包捕获环境变量析构顺序
    //析构顺序为闭包内变量排列顺序,与捕获的变量的声明顺序无关 存在析构变化
    // let z = PrintDrop("z");
    // let x = PrintDrop("x");
    // let y = PrintDrop("y");

    // let closure = move || {y; z; x;};

    let y = PrintDrop("y");
    let x = PrintDrop("x");
    let z = PrintDrop("z");

    //z的借用先被闭包捕获
    let closure = move || {
        {
            let z_ref = &z;
        }
        x; y; z;
    };
}
