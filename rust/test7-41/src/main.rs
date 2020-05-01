//RAII模式 示例
//信内容
#[derive(Clone)]
pub struct Letter {
    text : String,
}

//信封
pub struct Envelope {
    letter : Option<Letter>,
}

pub struct PickupLorryHandle {
    done : bool,
}

impl Letter {
    pub fn new(text : String) -> Self {
        Letter {
            text : text,
        }
    }
}

impl Envelope {
    pub fn wrap(&mut self, letter : &Letter) {
        self.letter = Some(letter.clone());
    }
}

pub fn buy_prestamped_envelope() -> Envelope {
    Envelope {letter : None}
}

impl PickupLorryHandle {
    pub fn pickup(&mut self, envelope : &Envelope) {

    }

    pub fn done(&mut self) {
        self.done = true;
        println!("sent");
    }
}

pub fn order_pickup() -> PickupLorryHandle {
    PickupLorryHandle {done : false}
}

/// 信封可能被复制多次
/// 信封里可能有信 也可能没信 或同一个信封装多个不同的信
/// 无法保证一定包信交给邮车了
fn main() {
    let letter = Letter::new(String::from("Dear RustFest"));
    let mut envelope = buy_prestamped_envelope();
    envelope.wrap(&letter);
    let mut lorry = order_pickup();
    lorry.pickup(&envelope);
    lorry.done();
}
