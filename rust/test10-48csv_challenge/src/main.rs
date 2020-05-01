mod opt;
mod err;
mod core;

use structopt::StructOpt;
// use self::opt::Opt;
// use self::core::read::{load_csv, write_csv};
use std::path::PathBuf;
use std::process;
// use self::core::{
//     read::{load_csv, write_csv},
//     write::replace_column,
// };
use test10_48csv_challenge::{
    Opt,
    {load_csv, write_csv},
    replace_column,
};


fn main() {
    //read
    let opt = Opt::from_args();
    let filename = PathBuf::from(opt.input);
    let csv_data = match load_csv(filename) {
        Ok(fname) => { fname },
        Err(e) => {
            println!("main error : {:?}", e);
            process::exit(1);
        }
    };

    //replace
    let modified_data = match replace_column(csv_data, &opt.column_name, &opt.replacement) {
        Ok(data) => { data },
        Err(e) => {
            println!("Main error : {:?}", e);
            process::exit(1);
        }
    };

    //write
    let output_file = &opt.output.unwrap_or("output/output.csv".to_string());
    match write_csv(&modified_data, &output_file) {
        Ok(_) => {
            println!("write sucess!");
        },
        Err(e) => {
            println!("main error : {:?}", e);
            process::exit(1);
        }
    }
}
