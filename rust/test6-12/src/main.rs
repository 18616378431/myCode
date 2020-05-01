//为结构体实现方法
#[derive(Debug)]
struct User {
    name : &'static str,
    avatar_url : &'static str,
}

impl User {
    fn show(&self) {
        println!("name : {:?}", self.name);
        println!("avatar_url : {:?}", self.avatar_url);
    }
}

fn main() {
    let user = User {
        name : "Alex",
        avatar_url : "https://avatar.com/alex",
    };

    user.show();
    //等价于
    User::show(&user);
}
