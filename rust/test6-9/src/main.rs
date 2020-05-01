//使用return提前返回
//欧几里得 辗转相除法计算两数的最大公约数
fn gcd(a : u32, b : u32) -> u32 {
    if b == 0 {
        return a;
    }

    return gcd(b, a % b);
}
fn main() {
    let g = gcd(60, 40);
    assert_eq!(20, g);
}
