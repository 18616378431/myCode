#![feature(proc_macro_hygiene)]

#[macro_use]
extern crate test12_46_proc_macro;

#[derive(A)]
struct A;

#[test]
fn test_derive_a() {
    assert_eq!("hello from impl A".to_string(), A.a());
}

use test12_46_proc_macro::attr_with_args;
#[attr_with_args("Hello,Rust!")]
fn foo() {

}

#[test]
fn test_foo() {
    assert_eq!(foo(), "Hello,Rust!");
}


use test12_46_proc_macro::hashmap;
#[test]
fn test_hashmap() {
    let hm = hashmap!{"a" : 1, "b" : 2};
    assert_eq!(hm["a"], 1);
    let hm = hashmap!{"a" => 1, "b" => 2, "c" => 3};
    assert_eq!(hm["c"], 3);
}