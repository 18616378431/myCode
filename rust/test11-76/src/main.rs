//future Pin Unpin
#![feature(pin)]
use std::pin::{Pin, Unpin};
use std::marker::Pinned;
use std::ptr::NonNull;

struct Unmovable {
    data : String,
    slice : NonNull<String>,
    _pin : Pinned,
}

impl Unpin for Unmovable {

}

impl Unmovable {
    fn new(data : String) -> Pin<Box<Self>> {
        let res = Unmovable {
            data,
            slice : NonNull::dangling(),
            _pin : Pinned,
        };
        let mut boxed = Box::pinned(res);
        let slice = NonNull::from(&boxed.data);
        unsafe {
            let mut_ref : Pin<&mut Self> = Pin::as_mut(&mut boxed);
            Pin::get_mut_unchecked(mut_ref).slice = slice;
        }
        boxed
    }
}

fn main() {
    let unmoved = Unmovable::new("hello".to_string());
    let mut still_unmoved = unmoved;
    assert_eq!(still_unmoved.slice, NonNull::from(&still_unmoved.data));
    let mut new_unmoved = Unmovable::new("world".to_string());
    std::mem::swap(&mut *still_unmoved, &mut *new_unmoved);
}
