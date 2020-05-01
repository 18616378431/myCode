//未绑定生命周期 transmute
use std::mem::transmute;

fn main() {
    let x : &i32;
    {
        let a = 12;
        let ptr = &a as *const i32;
        x = unsafe {
            transmute::<*const i32, &i32>(ptr)
        };
        //离开作用域形成悬垂指针
    }
    println!("hello {}", x);
}
