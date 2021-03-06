//浮点数格式化
fn main() {
    assert_eq!(format!("{:.4}", 1234.5678), "1234.5678");
    assert_eq!(format!("{:.2}", 1234.5618), "1234.56");
    assert_eq!(format!("{:.2}", 1234.5678), "1234.57");
    assert_eq!(format!("{:<10.4}", 1234.5678), "1234.5678 ");
    assert_eq!(format!("{:^12.2}", 1234.5618), "  1234.56   ");
    assert_eq!(format!("{:0^12.2}", 1234.5678), "001234.57000");
    assert_eq!(format!("{:e}", 1234.5678), "1.2345678e3");
}
