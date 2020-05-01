//字符串查找 存在性判断
fn main() {
    let bananas = "bananas";
    assert!(bananas.contains('a'));
    assert!(bananas.contains("an"));
    assert!(bananas.contains(char::is_lowercase));
    assert!(bananas.starts_with('b'));
    assert!(!bananas.ends_with("nana"));
}
