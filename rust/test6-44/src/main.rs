//将闭包做为trait对象
//trait限定,静态分发
//trait对象,动态分发,有运行时消耗
trait Any {
    fn any(&self, f : &(Fn(u32) -> bool)) -> bool;
}

impl Any for Vec<u32> {
    fn any(&self, f: &(Fn(u32) -> bool)) -> bool {
        for &x in self.iter() {
            if f(x) {
                return true;
            }
        }
        false
    }
}

fn main() {
    let v : Vec<u32> = vec![1, 2, 3];
    let b = v.any(&|x| x == 3);
    println!("{:?}", b);
}
