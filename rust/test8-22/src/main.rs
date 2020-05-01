//捕获匹配 matches rmatches matches_indices rmatches_indices
fn main() {
    let v = "abcXXXabcYYYabc".matches("abc").collect::<Vec<&str>>();
    assert_eq!(v, ["abc", "abc", "abc"]);

    let v = "1abc2abc3".rmatches(char::is_numeric).collect::<Vec<&str>>();
    assert_eq!(v, ["3", "2", "1"]);

    let v = "abcXXXabcYYYabc".match_indices("abc").collect::<Vec<_>>();
    assert_eq!(v, [(0, "abc"), (6, "abc"), (12, "abc")]);

    let v = "abcXXXabcYYYabc".rmatch_indices("abc").collect::<Vec<_>>();
    assert_eq!(v, [(12, "abc"), (6, "abc"), (0, "abc")]);
}
