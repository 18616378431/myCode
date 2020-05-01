//利用Cow<T>实现统一规范
use std::borrow::Cow;
use std::thread;

#[derive(Debug)]
struct Token<'a> {
    raw : Cow<'a, str>,
}

impl<'a> Token<'a> {
    pub fn new<S>(raw : S) -> Token<'a> 
        where 
        S : Into<Cow<'a, str>>,
    {
        Token {raw : raw.into()}   
    }
}

fn main() {
    //Cow的字符串字面量和String可跨线程安全传递
    let token = Token::new("abc123");
    let token1 = Token::new("api.example.io".to_string());
    thread::spawn(move || {
        println!("token : {:?}", token);
        println!("token : {:?}", token1);
    }).join().unwrap();

    //字符串切片因生命周期问题无法跨线程安全传递
    let raw = String::from("abc");
    let s = &raw[..];
    let token = Token::new(s);
    thread::spawn(move || {
        println!("token : {:?}", token);
    }).join().unwrap();
}
