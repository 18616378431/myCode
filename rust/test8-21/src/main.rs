//split splitn split_terminator 分割字符串
fn main() {
    let s = "Lowe 虎 Leopard";
    let v = s.split(|c| 
    (c as u32) >= (0x4E00 as u32) && (c as u32) <= (0x9F5A as u32)
    ).collect::<Vec<&str>>();
    assert_eq!(v, ["Lowe ", " Leopard"]);

    let v = "abc1defXghi".split(|c|
        c == '1' || c == 'X'
    ).collect::<Vec<&str>>();
    assert_eq!(v, ["abc", "def", "ghi"]);

    let v = "Mary had a little lambda".splitn(3, ' ').collect::<Vec<&str>>();
    assert_eq!(v, ["Mary", "had", "a little lambda"]);

    let v = "A.B.".split(".").collect::<Vec<&str>>();
    assert_eq!(v, ["A", "B", ""]);

    let v = "A.B.".split_terminator(".").collect::<Vec<&str>>();
    assert_eq!(v, ["A", "B"]);

    let v = "A..B..".split(".").collect::<Vec<&str>>();
    assert_eq!(v, ["A", "", "B", "", ""]);

    let v = "A..B..".split_terminator(".").collect::<Vec<&str>>();
    assert_eq!(v, ["A", "", "B", ""]);
}
