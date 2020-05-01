//结构体中的引用成员标注生命周期参数
/// 生命周期省略规则
/// 1.每个参数位置上省略的生命周期参数都将成为不同的生命周期参数'a 'b 'c
/// 2.如果只有一个输入参数,则其生命周期参数将分配给返回值
/// 3.如果存在多个输入生命周期位置,但包含&self或&mut self,则self的生命周期参数将分配给输出
/// 
#[derive(Debug)]
struct Foo<'a> {
    part : &'a str,
}

impl<'a> Foo<'a> {
    fn split_first(s : &'a str) -> &'a str {
        s.split(',').next().expect("Could not find a ','")
    }

    fn new(s : &'a str) -> Self {
        Foo {part : Foo::split_first(s)}
    }

    fn get_part(&self) -> &str {
        self.part
    }
}

fn main() {
    let words = String::from("Sometimes think,the greatest sorrow than older");
    // println!("{:?}", Foo::new(words.as_str()));
    let foo = Foo::new(words.as_str());
    println!("{:?}", foo.get_part());
}
