//hashmap!宏


//宏展开
//cargo rustc -- -Z unstable-options --pretty=expanded


//最后一个元素不可有逗号,加逗号会出错 [1]
// macro_rules! hashmap {
//     ($($key:expr => $value:expr),*) => {
//         {
//             let mut _map = ::std::collections::HashMap::new();
//             $(
//                 _map.insert($key, $value);
//             )*
//             _map
//         }
//     };
// }

//通过递归调用消除最后的逗号
// macro_rules! hashmap {
//     ($($key:expr => $value:expr,)*) => { hashmap!($($key => $value),*); };
//     ($($key:expr => $value:expr),*) => {
//         {
//             let mut _map = ::std::collections::HashMap::new();
//             $(
//                 _map.insert($key, $value);
//             )*
//             _map
//         }
//     };
// }

//利用重复匹配来匹配结尾逗号
// macro_rules! hashmap {
//     ($($key:expr => $value:expr),* $(,)*) => {
//         {
//             let mut _map = ::std::collections::HashMap::new();
//             $(
//                 _map.insert($key, $value);
//             )*
//             _map
//         }
//     };
// }

//预分配HashMap容量
// macro_rules! unit {
//     ($($x:tt)*) => (());
// }

// macro_rules! count {
//     ($($key:expr),*) => (<[()]>::len(&[$(unit!($key)),*]));
// }

// macro_rules! hashmap {
//     ($($key:expr => $value:expr),* $(,)*) => {
//         {
//             let _cap = count!($($key),*);
//             let mut _map = ::std::collections::HashMap::with_capacity(_cap);
//             $(
//                 _map.insert($key, $value);
//             )*
//             _map
//         }
//     };
// }

//使用内部宏解决宏依赖
macro_rules! hashmap {
    (@unit $($x:tt)*) => (());
    (@count $($rest:expr),*) => (<[()]>::len(&[$(hashmap!(@unit $rest)),*]));
    ($($key:expr => $value:expr),* $(,)*) => {
        {
            let _cap = hashmap!(@count $($key),*);
            println!("{}", _cap);
            let mut _map = ::std::collections::HashMap::with_capacity(_cap);
            $(
                _map.insert($key, $value);
            )*
            _map
        }
    };
}

//宏展开跟踪
//[1] 编译期命令
//[2] nightly版本的 #![feature(trace_macros)]

fn main() {
    //nightly trace_macros!(true)
    let map = hashmap! {
        "a" => 1,
        "b" => 2,
        "c" => 3,
    };
    assert_eq!(map["a"], 1);
}


