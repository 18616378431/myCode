//entry
use std::collections::HashMap;

fn main() {
    let mut map : HashMap<&str, u32> = HashMap::new();
    map.entry("current_year").or_insert(2017);
    assert_eq!(map["current_year"], 2017);
    *map.entry("current_year").or_insert(2017) += 10;
    assert_eq!(map["current_year"], 2027);
    let last_leap_year = 2016;
    map.entry("next_leap_year").or_insert_with(|| last_leap_year + 4);
    assert_eq!(map["next_leap_year"], 2020);
    assert_eq!(map.entry("current_year").key(), &"current_year");
}
