//函数
fn func_name(arg1 : u32, arg2 : String) -> Vec<u32> {
    //函数体
    vec![1]
}

//将语言关键字用作函数名 raw identifier r#match
fn r#match(needle : &str, haystack : &str) -> bool {
    haystack.contains(needle)
}

fn main() {
    assert!(r#match("foo", "foobar"));
}
