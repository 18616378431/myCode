//创建者模式
use std::process::Command;

fn main() {
    Command::new("ls").arg("-l").arg("-a").spawn().expect("ls command failed to start");
}
