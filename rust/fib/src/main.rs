fn main() {
    // for i in 1..51 {
    //     println!("{}:{}",i,fib(i));
    // }

    let mut a:A = A::new();
    
    a.set(100 as f64, 200 as f64);


    println!("{:?}",a);
    println!("x:{},y:{}",a.getx(),a.gety());
    a.show();
}

// fn fib(n :u64) -> u64{
//     if n == 1 || n == 2 {
//         1
//     } else {
//         fib(n - 2) + fib(n - 1)
//     }
// }

#[derive(Debug)]
struct A{
    x:f64,
    y:f64
}

trait B{
    fn new() -> A;
    fn set(& mut self,m:f64,n:f64);
    fn getx(&self) -> f64;
    fn gety(&self) -> f64;
    fn show(&self);
}

impl B for A{
    fn new() -> A{
        A{x:0 as f64,y:0 as f64}
    }
    fn set(&mut self,m:f64,n:f64){
        self.x = m;
        self.y = n;
    }

    fn getx(&self) -> f64{
        self.x
    }

    fn gety(&self) -> f64{
        self.y
    }

    fn show(&self){
        println!("x:{},y:{}",self.x,self.y);
    }
}


