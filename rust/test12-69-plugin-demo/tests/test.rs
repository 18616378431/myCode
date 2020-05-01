//编译器插件
#![feature(plugin)]
#![plugin(test12_69_plugin_demo)]


// #[cfg(test)]
// mod tests {
//     #[test]
//     fn it_works() {
//         assert_eq!(2 + 2, 4);
//     }
// }

#[test]
fn test_plugin() {
    assert_eq!(roman_to_digit(MMXVIII), 2018);
}