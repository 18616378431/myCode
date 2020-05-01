//replace swap
fn main() {
    let mut v : Vec<i32> = vec![1, 2];
    let v_ptr : *mut i32 = v.as_mut_ptr();
    unsafe {
        let old_v = v_ptr.replace(5);
        assert_eq!(1, old_v);
        assert_eq!([5, 2], &v[..]);
    }

    let mut v : Vec<i32> = vec![1, 2];
    let v_ptr = &mut v as *mut Vec<i32>;
    unsafe {
        let old_v = v_ptr.replace(vec![3, 4, 5]);
        assert_eq!([1, 2], &old_v[..]);
        assert_eq!([3, 4, 5], &v[..]);
    }

    let mut array = [0, 1, 2, 3];
    let x = array[0..].as_mut_ptr() as *mut [u32; 2];
    let y = array[1..].as_mut_ptr() as *mut [u32; 2];
    unsafe {
        assert_eq!([0, 1], x.read());
        assert_eq!([1, 2], y.read());
        //tmp = x;
        //x = y;
        //y = x;
        x.swap(y);
        assert_eq!([1, 0, 1, 3], array);
    }
}
