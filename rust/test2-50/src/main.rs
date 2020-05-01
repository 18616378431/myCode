//Box<T> 智能指针
fn main() {
    #[derive(PartialEq, Debug)]
    struct Point {
        x : f64,
        y : f64,
    }

    let box_point = Box::new(Point{x : 0.0, y : 0.0});
    let unboxed_point = *box_point;
    assert_eq!(unboxed_point, Point{x : 0.0, y : 0.0});
}
