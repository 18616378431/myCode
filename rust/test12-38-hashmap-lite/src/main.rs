//导入导出宏
//2015
// #[macro_use] extern crate test12_38_hashmap_lite;

//2018
use test12_38_hashmap_lite::hashmap;

fn main() {
    let map = hashmap! {
        "a" => 1,
        "b" => 2,
        "c" => 3,
    };
    assert_eq!(map["a"], 1);
}
