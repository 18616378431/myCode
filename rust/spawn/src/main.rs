extern crate rand;
// extern crate time;
extern crate chrono;

use std::thread;
// use std::time::Duration;
// use std::time::*;
// use std::time::{SystemTime, UNIX_EPOCH};
use rand::Rng;

use chrono::prelude::*;

fn main() {
    let dt = Local::now();
    let start = dt.timestamp_millis();

    // thread::sleep(Duration::from_secs(2));

    let handlers : Vec<_> = (0..8).map(|_| {
        thread::spawn(|| {
            let mut rng = rand::thread_rng();
            let mut x = rng.gen::<i32>();
            let num = 5_000_000;
            for i in 0..num {
                if (x + i) % 2 == 0 {
                    x += i;
                } else {
                    x -= i;
                }
            }
            x
        })
    }).collect();

    for h in handlers {
        println!("Thread finished with count = {}",
            h.join().map_err(|_| "Could not join a thread").unwrap());
    }

    let dt = Local::now();
    let end = dt.timestamp_millis();

    let duration = end - start;

    println!("耗时:{} ms",duration);
}
