//函数屏蔽,函数定义仅在当前作用域有效并且会屏蔽作用域外的同名函数
fn f() {
    println!("1");
}

fn main() {
    f();//2
    {
        f();//3

        fn f() {
            println!("3");
        }
    }

    f();
    fn f() {
        println!("2");
    }
}
