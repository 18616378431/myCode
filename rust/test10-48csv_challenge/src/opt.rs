//解析命令行参数
use structopt_derive::*;
#[derive(Debug, StructOpt)]
#[structopt(name = "test10-48csv_challenge", about = "Usage")]
pub struct Opt {
    #[structopt(help = "Input File")]
    pub input : String,
    #[structopt(help = "Column Name")]
    pub column_name : String,
    #[structopt(help = "Replacement Column Name")]
    pub replacement : String,
    #[structopt(help = "Output file,stdout if not present")]
    pub output : Option<String>,
}