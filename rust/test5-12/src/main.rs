//let默认创建词法作用域
//每个let声明都会创建词法作用域

///作用域伪代码
/// 'a{
///     let a = "";
///    'b{
///         let b = "";
///         'c{
///             let c = "";
///             'd{
///                 let d = c;
///             }
///         }
///     }
/// 
/// }
fn main() {
    let a = "hello";
    let b = "rust";
    let c = "world";
    let d = c;//字符串字面量支持按复制,复制语义
}