//HashMap合并 extend chain 
use std::collections::HashMap;

fn merge_extend<'a> (
    map1 : &mut HashMap<&'a str,&'a str>, 
    map2 : HashMap<&'a str,&'a str>
    ) {
    map1.extend(map2);
}

fn merge_chain<'a>(
    map1 : HashMap<&'a str, &'a str>,
    map2 : HashMap<&'a str, &'a str>,
    ) -> HashMap<&'a str, &'a str>{
    map1.into_iter().chain(map2).collect()
}

fn merge_by_ref<'a>(
    map : &mut HashMap<&'a str, &'a str>,
    map_ref : &HashMap<&'a str, &'a str>,
) {
    map.extend(map_ref.into_iter().map(|(k, v)| {(k.clone(), v.clone())}))
}

fn main() {
    let mut book_reviews1 = HashMap::new();
    book_reviews1.insert("Rust Book", "good");
    book_reviews1.insert("Programming Rust", "nice");
    book_reviews1.insert("The Tao of Rust", "deep");

    let mut book_reviews2 = HashMap::new();
    book_reviews2.insert("Rust in Action", "good");
    book_reviews2.insert("Rust Primer", "nice");
    book_reviews2.insert("Matering Rust", "deep");

    //转移所有权 将map2合并到map1中
    merge_extend(&mut book_reviews1, book_reviews2);
    println!("{:?},len : {}", book_reviews1,book_reviews1.len());
    // println!("{:?}", book_reviews2);

    //转移所有权 返回HashMap
    // let book_reviews1 = merge_chain(book_reviews1, book_reviews2);
    // println!("{:?},len : {}", book_reviews1,book_reviews1.len());
    // println!("{:?}", book_reviews2);

    //可变借用和不可变借用 不转移所有权
    // merge_by_ref(&mut book_reviews1, &book_reviews2);
    // println!("{:?},len : {}", book_reviews1, book_reviews1.len());
    // println!("{:?}", book_reviews2);

    // for key in book_reviews1.keys() {
    //     println!("{}", key);
    // }
}
