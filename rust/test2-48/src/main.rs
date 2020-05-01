//HashSet<K> BTreeSet<K>
//HashSet<Key, ()> BTreeSet<Key, ()>

use std::collections::HashSet;
use std::collections::BTreeSet;

fn main() {
    let mut hbooks = HashSet::new();
    let mut bbooks = BTreeSet::new();

    hbooks.insert("A Song of Ice and Fire");
    hbooks.insert("The Emerald City");
    hbooks.insert("The Odyssey");

    if !hbooks.contains("The Emerald City") {
        println!("We have {} books, but The Emerald City ain't one.", hbooks.len());
    }

    println!("{:?}", hbooks);

    bbooks.insert("A Song of Ice and Fire");
    bbooks.insert("The Emerald City");
    bbooks.insert("The Odyssey");

    println!("{:?}", bbooks);
}
