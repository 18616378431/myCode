//父线程中的引用无法在子线程中安全地使用
fn main() {
    let array = [1, 2, 3];
    let mut guards = vec![];
    for &i in &array {
        let guard = std::thread::spawn(move || {
            println!("element : {}", i);
        });
        guards.push(guard);
    }
    for guard in guards {
        guard.join().unwrap();
    }
}
