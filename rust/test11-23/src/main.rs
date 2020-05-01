//死锁
extern crate rand;
use std::thread;
use std::sync::{Arc, Mutex};

fn flip_simulate(target_flips : u64, total_flips : Arc<Mutex<u64>>) {
    let mut continue_positive = 0;//正面次数
    let mut iter_counts = 0;//总次数
    while continue_positive <= target_flips {
        iter_counts += 1;
        let pro_or_con = rand::random();
        if pro_or_con {
            continue_positive += 1;
        } else {
            continue_positive = 0;
        }
    }
    println!("iter_counts : {}", iter_counts);
    let mut total_flips = total_flips.lock().unwrap();
    *total_flips += iter_counts;
}

fn main() {
    let total_flips = Arc::new(Mutex::new(0));
    let completed = Arc::new(Mutex::new(0));
    let runs = 8;
    let target_flips = 10;
    for _ in 0..10 {
        let total_flips = total_flips.clone();
        let completed = completed.clone();
        thread::spawn(move || {
            flip_simulate(target_flips, total_flips);
            let mut completed = completed.lock().unwrap();
            *completed += 1;
        });
    }
    //死锁
    // let completed = completed.lock().unwrap();
    // while *completed < runs {}
    // let total_flips = total_flips.lock().unwrap();
    // println!("Final average : {}", *total_flips / *completed);

    loop {
        let completed = completed.lock().unwrap();
        if *completed == runs {
            let total_flips = total_flips.lock().unwrap();
            println!("Final average : {}", *total_flips / *completed);
            break;
        }
    }
}
