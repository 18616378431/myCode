// #[cfg(test)]
// mod tests {
//     #[test]
//     fn it_works() {
//         assert_eq!(2 + 2, 4);
//     }
// }

#![feature(proc_macro_hygiene)]

//过程宏 自定义派生属性
extern crate proc_macro;
use self::proc_macro::TokenStream;
#[proc_macro_derive(A)]
pub fn derive(input : TokenStream) -> TokenStream {
    let input = input.to_string();
    assert!(input.contains("struct A;"));
    r#"
        impl A {
            fn a(&self) -> String {
                format!("hello from impl A")
            }
        }
    "#.parse().unwrap()
}

//自定义属性 自定义派生属性是自定义属性的特例
#[proc_macro_attribute]
pub fn attr_with_args(args : TokenStream, input : TokenStream) -> TokenStream {
    let args = args.to_string();
    let input = input.to_string();
    format!("fn foo() -> &'static str {{ {} }}", args).parse().unwrap()
}

//Bang宏
#[proc_macro]
pub fn hashmap(input : TokenStream) -> TokenStream {
    let input = input.to_string();
    let input = input.trim_right_matches(',');
    let input : Vec<String> = input.split(",").map(|n| {
        let mut data = if n.contains(":") {
            n.split(":")
        } else {
            n.split("=>")
        };
        let (key, value) = (data.next().unwrap(), data.next().unwrap());
        format!("hm.insert({}, {})", key, value)
    }).collect();
    let count : usize = input.len();
    let tokens = format!("
        {{
            let mut hm = ::std::collections::HashMap()::with_capacity({});
            {}
            hm
        }}", count, input.iter().map(|n| format!("{};", n)).collect::<String>());
        tokens.parse().unwrap()
}