//自定义内部可变结构体 协变 存在未定义行为风险
// struct MyCell<T> {
//     value : T,
// }

//逆变 Rust借用检查器起作用
use std::marker::PhantomData;

struct MyCell<T> {
    value : T,
    mark : PhantomData<fn(T)>,//逆变 fn(T)为逆变
}

impl<T : Copy> MyCell<T> {
    fn new(x : T) -> MyCell<T> {
        // MyCell {value : x}
        MyCell {value : x, mark : PhantomData}
    }

    fn get(&self) -> T {
        self.value
    }

    fn set(&self, value : T) {
        use std::ptr;
        unsafe {
            ptr::write(&self.value as *const _ as *mut _, value);
        }
    }
}

fn step1<'a>(r_c1 : &MyCell<&'a i32>) {
    let val : i32 = 13;
    step2(&val, r_c1);
    println!("step1 value : {}", r_c1.value);
}

fn step2<'b>(r_val : &'b i32, r_c2 : &MyCell<&'b i32>) {
    r_c2.set(r_val);
}

static X : i32 = 10;

fn main() {
    let cell = MyCell::new(&X);
    step1(&cell);
    println!("end value : {}", cell.value);
}
