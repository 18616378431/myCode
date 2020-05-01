//Box<Any> downcast::<String> = Result<T, E> 独占所有权
use std::any::Any;

fn print_if_string(value : Box<Any>) {
    if let Ok(string) = value.downcast::<String>() {
        println!("String (length : {}) : {}", string.len(), string);
    } else {
        println!("Not String");
    }
}

fn main() {
    let my_string = "Hello World".to_string();
    print_if_string(Box::new(my_string));
    print_if_string(Box::new(0i8));
}
