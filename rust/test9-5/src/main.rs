//Option<T> Some None 判断有和无
fn get_shortest(names : Vec<&str>) -> Option<&str> {
    if names.len() > 0 {
        let mut shortest = names[0];
        for name in names.iter() {
            if name.len() < shortest.len() {
                shortest = *name;
            }
        }
        Some(shortest)
    } else {
        None
    }
}

fn show_shortest(names : Vec<&str>) -> &str {
    match get_shortest(names) {
        Some(shortest)  => shortest,
        None            => "Not Found",
    }

    // //取出Some内的值,None则引发线程恐慌
    // get_shortest(names).unwrap();
    // //指定处理None的情况
    // get_shortest(names).unwrap_or("Not Found");
    // //可以指定闭包
    // get_shortest(names).unwrap_or_else(|| "Not Found");
    // //遇到None引发线程恐慌
    // get_shortest(names).expect("Not Found");
}

fn get_shortest_length(names : Vec<&str>) -> Option<usize> {
    match get_shortest(names) {
        Some(shortest)  => Some(shortest.len()),
        None            => None,
    }
}

fn get_shortest_length_map(names : Vec<&str>) -> Option<usize> {
    //map实际上是对match的包装
    get_shortest(names).map(|name| name.len())
}

fn main() {
    assert_eq!(show_shortest(vec!["Uku", "Felipe"]), "Uku");
    assert_eq!(show_shortest(Vec::new()), "Not Found");

    assert_eq!(get_shortest_length(vec!["Uku", "Felipe"]), Some(3));
    assert_eq!(get_shortest_length(Vec::new()), None);

    assert_eq!(get_shortest_length_map(vec!["Uku", "Felipe"]), Some(3));
    assert_eq!(get_shortest_length_map(Vec::new()), None);
}
