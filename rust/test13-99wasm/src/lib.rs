#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}

//cargo build --target wasm32-unknown-unknown
//cp target/wasm32-unknown-unknown/debug/test13_99wasm.wasm output
//wasm-gc output/test13_99wasm.wasm output/small_hello.wasm

#[link(wasm_import_module = "env")]
extern "C" {
    pub fn logit();
    pub fn hello(ptr : *const u8, len : u32);
}

#[no_mangle]
pub extern "C" fn add_one(x : i32) {
    unsafe {
        logit();
        let msg = format!("Hello World! {}", x + 1);
        hello(msg.as_ptr(), msg.len() as u32);
    }
} 
