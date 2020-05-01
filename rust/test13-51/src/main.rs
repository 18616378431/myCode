//rust中调用C
extern "C" {
    fn isalnum(input : i32) -> i32;
}
fn main() {
    unsafe {
        println!("Is 3 a number ? the answer is : {}", isalnum(3));
        // println!("Is 'a' a number ? the answer is : {}", isalnum('a'));
    }
}
