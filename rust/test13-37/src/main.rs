//ManuallyDrop手动指定析构函数调用顺序
use std::mem::ManuallyDrop;

struct Peach;

struct Banana;

struct Melon;

struct FruitBox {
    peach : ManuallyDrop<Peach>,
    melon : Melon,
    banana : ManuallyDrop<Banana>,
}

impl Drop for FruitBox {
    fn drop(&mut self) {
        unsafe {
            ManuallyDrop::drop(&mut self.peach);
            ManuallyDrop::drop(&mut self.banana);
        }
    }
}


fn main() {
    println!("Hello, world!");
}
