struct A{
    x:f64,
    y:f64
}

trait B{
    fn set(&self);
    fn getx(&self);
    fn gety(&self);
    fn show(&self);
}

impl B for A{
    fn set(&self,m:f64,n:f64){
        self.x = m;
        self.y = n;
    }

    fn getx(&self){
        self.x
    }

    fn gety(&self){
        self.y
    }

    fn show(&self){
        println!("x:{},y:{}",self.x,self.y);
    }
}

