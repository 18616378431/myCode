//将字符串转换为其他类型 format!
/// {:number.substr}
/// < 左对齐
/// > 右对齐
/// ^居中对齐
/// :*填充
fn main() {
    let s : String = format!("{}Rust", "Hello");
    assert_eq!(s, "HelloRust");
    assert_eq!(format!("{:5}", "HelloRust"), "HelloRust");
    assert_eq!(format!("{:5.3}", "HelloRust"), "Hel  ");
    assert_eq!(format!("{:10}", "HelloRust"), "HelloRust ");
    assert_eq!(format!("{:<12}", "HelloRust"), "HelloRust   ");
    assert_eq!(format!("{:>12}", "HelloRust"), "   HelloRust");
    assert_eq!(format!("{:^12}", "HelloRust"), " HelloRust  ");
    assert_eq!(format!("{:^12.5}", "HelloRust"), "   Hello    ");
    assert_eq!(format!("{:=^12.5}", "HelloRust"), "===Hello====");
    assert_eq!(format!("{:*^12.5}", "HelloRust"), "***Hello****");
    assert_eq!(format!("{:5}", "th\u{e9}"), "th\u{e9}  ");
}
