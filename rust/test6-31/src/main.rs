//闭包被翻译为匿名结构体和trait
#![feature(unboxed_closures, fn_traits)]
struct Closure<'a> {
    env_var : &'a u32,
}

impl<'a> FnOnce<()> for Closure<'a> {
    type Output = ();
    extern "rust-call" fn call_once(self, args : ()) -> () {
        println!("{:?}", self.env_var);
    }
}

impl<'a> FnMut<()> for Closure<'a> {
    extern "rust-call" fn call_mut(&mut self, args : ()) -> () {
        println!("{:?}", self.env_var);
    }
}

impl<'a> Fn<()> for Closure<'a> {
    extern "rust-call" fn call(&self, args : ()) -> () {
        println!("{:?}", self.env_var);
    }
}

fn main() {
    let env_var = 42;
    let mut c = Closure {env_var : &env_var};
    c();
    c.call_mut(());
    c.call_once(());
}
