//借用规则
fn compute(input : &u32, output : &mut u32) {
    if *input > 10 {
        *output = 1;
    }

    if *input > 5 {
        *output *= 2;
    }
}

//optimize
fn compute_1(input : &u32, output : &mut u32) {
    let cached_input = *input;

    if cached_input > 10 {
        *output = 2;
    } else if cached_input > 5 {
        *output = 2;
    }
}

fn main() {
    let mut i = 20;
    let mut o = 5;
    compute(&i, &mut o);

    // compute(&i, &mut i);

    println!("{:?}", o);

    compute_1(&i, &mut o);

    println!("{:?}", o);
}
