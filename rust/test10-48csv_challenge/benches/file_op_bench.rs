#![feature(test)]
//feature 特性仅可在夜版使用
extern crate test;
use test::Bencher;
use std::path::PathBuf;
use test10_48csv_challenge::{
    Opt,
    {load_csv, write_csv},
    replace_column,
};

#[bench]
fn bench_read_100times(b : &mut Bencher) {
    b.iter(|| {
        let n = test::black_box(100);
        (0..n).fold(0, |_, _| {
            test_load_csv();
            0
        });
    });
}

fn test_load_csv() {
    let filename = PathBuf::from("./input/challenge.csv");
    load_csv(filename);
}