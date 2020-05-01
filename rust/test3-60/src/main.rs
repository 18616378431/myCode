//Vec<T>实现Deref
fn foo(s : &[i32]) {
    println!("{:?}", s[0]);
}

fn main() {
    let v = vec![1,2,3];
    foo(&v);
}
