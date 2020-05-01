//访问Union中的字段不进行任何安全检查
//union中的字段必须是可copy的
//U,Value,MyZero 共同模拟了MyEnumZero
#[repr(C)]
union U {
    i : i32,
    f : f32,
}

#[repr(C)]
struct Value {
    tag : u8,
    value : U,
}

#[repr(C)]
union MyZero {
    i : Value,
    f : Value,
}

enum MyEnumZero {
    I(i32),
    F(f32),
}

fn main() {
    let int_0 = MyZero{i : Value{tag : b'0', value : U{i : 0}}};
    let float_0 = MyZero{f : Value{tag : b'1', value : U{f : 0.0}}};
}
