//rayon 顺序计算转换为安全的并行计算,无数据竞争
extern crate rayon;
use rayon::prelude::*;

fn sum_of_squares(input : &[i32]) -> i32 {
    input.par_iter().map(|&i| i * i).sum()
}

fn increment_all(input : &mut [i32]) {
    input.par_iter_mut().for_each(|p| *p += 1);
}

fn main() {
    let v = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let r = sum_of_squares(&v);
    println!("{}", r);
    let mut v = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    increment_all(&mut v);
    println!("{:?}", v);
}
