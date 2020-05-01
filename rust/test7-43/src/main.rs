//RAII模式实现资源安全使用
pub struct Letter {
    text : String,
}

pub struct EmptyEnvelope {}

pub struct ClosedEnvelope {
    letter : Letter,
}

pub struct PickupLorryHandle {
    done : bool,
}

impl Letter {
    pub fn new(text : String) -> Self {
        Letter {text : text}
    }
}

impl EmptyEnvelope {
    pub fn wrap(self, letter : Letter) -> ClosedEnvelope {
        ClosedEnvelope {letter : letter}
    }
}

pub fn by_prestamped_envelope() -> EmptyEnvelope {
    EmptyEnvelope{}
}

impl PickupLorryHandle {
    pub fn pickup(&mut self, envelope : ClosedEnvelope) {

    }

    pub fn done(self) {

    }
}

impl Drop for PickupLorryHandle {
    fn drop(&mut self) {
        println!("sent");
    }
}

pub fn order_pickup() -> PickupLorryHandle {
    PickupLorryHandle {done : false}
}

fn main() {
    let letter = Letter::new(String::from("Dear RustFest"));
    let envelope = by_prestamped_envelope();
    let closed_envelope = envelope.wrap(letter);//转移所有权
    let mut lorry = order_pickup();
    lorry.pickup(closed_envelope);
}
