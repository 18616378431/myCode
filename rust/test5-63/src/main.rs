//NLL none lexcial lifetime 非词法作用域生命周期
fn capitalize(data : &mut [char]) {

}

fn foo(){
    let mut data = vec!['a', 'b', 'c'];
    let slice = &mut data[..];
    capitalize(slice);
    data.push('d');
}

fn main() {
    foo();
}
