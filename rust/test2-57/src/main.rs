//main 函数中返回Result<T,E>

use std::fs::File;

fn main() -> Result<(), std::io::Error> {
    let f = File::open("bar.txt");

    Ok(())
}
