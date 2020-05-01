//自定义错误类型CliError
//从文件中读取数字并累加求和 处理不同类型的错误
//try!宏
// #[feature(try_trait)]
//使用第三方库实现异常处理

extern crate failure;
#[macro_use] extern crate failure_derive;

use failure::{Context, Fail, Backtrace};

use std::env;
use std::fs::File;
use std::io::prelude::*;
use std::error::Error;
use std::process;
use std::io;
use std::fmt;
use std::num;
// use std::option::NoneError;

//自定义类型
type ParseResult<i32> = Result<i32, CliError>;

//自定义错误类型
#[derive(Debug)]
enum CliError {
    Io(io::Error),
    Parse(num::ParseIntError),
    // NoneError(NoneError),
}

impl fmt::Display for CliError {
    fn fmt(&self, f : &mut fmt::Formatter) -> fmt::Result {
        match *self {
            CliError::Io(ref err) => write!(f, "IO error : {}", err),
            CliError::Parse(ref err) => write!(f, "Parse error : {}", err),
            // CliError::NoneError(ref err) => write!(f, "Command args error : {:?}", err),
        }
    }
}

impl Error for CliError {
    fn description(&self) -> &str {
        match *self {
            CliError::Io(ref err) => err.description(),
            CliError::Parse(ref err) => Error::description(err),
            // CliError::NoneError(ref err) => "NoneError",
        }
    }

    fn cause(&self) -> Option<&Error> {
        match *self {
            CliError::Io(ref err) => Some(err),
            CliError::Parse(ref err) => Some(err),
            // _ => None,
        }
    }
}

impl From<io::Error> for CliError {//将错误类型转换为自定义类型CliError
    fn from(err : io::Error) -> CliError {
        CliError::Io(err)
    }
}

impl From<num::ParseIntError> for CliError {
    fn from(err : num::ParseIntError) -> CliError {
        CliError::Parse(err)
    }
}

// impl From<NoneError> for CliError {
//     fn from(err : NoneError) -> CliError {
//         CliError::NoneError(err)
//     }
// }

// fn main() {
fn main() -> Result<(), i32> {
    //main函数中如果没有传递文件名参数,取索引1会报线程崩溃
    // let args : Vec<String> = env::args().collect();
    // println!("{:?}", args);
    // let filename = &args[1];
    // println!("In file {:?}", filename);

    //改进 nth存在返回Option Some 不存在返回None
    // let filename = env::args().nth(1);

    // match run(filename) {
    //     Ok(n) => {println!("{:?}", n);}
    //     Err(e) => {
    //         println!("main error : {}", e);
    //         process::exit(1);
    //     }
    // }

    //main函数中返回值
    let filename = env::args().nth(1);
    match run(filename) {
        Ok(n) => {
            println!("{:?}", n);
            return Ok(());
        },
        Err(e) => {
            return Err(1);
        }
    }
}


//使用问号操作符代替try!宏 向上返回错误
// fn run(filename : &str) -> ParseResult<i32> {
fn run(filename : Option<String>) -> ParseResult<i32> {
    // let mut file = try!(File::open(filename));
    // let mut file = File::open(filename?)?;
    let filen = match filename {
        Some(v) => v,
        None => String::new(),
    };

    let mut file = File::open(filen)?;
    let mut contents = String::new();
    // try!(file.read_to_string(&mut contents));
    file.read_to_string(&mut contents)?;
    let mut sum = 0;
    for c in contents.lines() {
        // let n : i32 = try!(c.parse::<i32>());
        let n : i32 = c.parse::<i32>()?;
        sum += n;
    }
    Ok(sum)
}

