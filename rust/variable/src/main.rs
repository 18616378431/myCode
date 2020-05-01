fn main() {
    //
    let a : i8 = 1;
    let b : u8 = 100;
    
    let c : i16 = 2;
    let d : u16 = 200;

    let e : i32 = 3;
    let f : u32 = 300;
    
    let g : i64 = 4;
    let h : u64 = 400;

    let i : f32 = 0.64;
    let j : f64 = 0.00054;

    let mut vec : Vec<u8> = Vec::new();

    vec.push(1);

    println!("{:?}",vec);

    let vec1 = vec![1,2,3,4,5];

    println!("{:?}",vec1);

    let mut my_str : String = String::from("abcdef");

    println!("{}",my_str);

    let mut counter : u32 = 0;

    loop {
        counter += 1;

        if counter == 10 {
            break;
        }
        println!("{}",counter);
    }

    let x = if true {
        100
    } else {
        200
    };

    println!("{}",x);

    println!("{}",my_fn(10, 20));

    let y = loop{
        counter += 1;

        if counter == 300 {
            break counter;
        }
    };

    println!("{}",y);
}

fn my_fn(a : i32, b : i32) -> i32 {
    a + b
}
