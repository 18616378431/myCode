//数组做为函数参数
fn main() {
    let arr : [u32] = [1,2,3,4,5];
    reset(arr);

    println!("{:?}", arr);
}

fn reset(mut arr : [u32]) {
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;

    println!("{:?}", arr);
}