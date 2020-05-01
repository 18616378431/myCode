//格式化自定义类型
use std::fmt::{Display, self, Formatter};

struct City {
    name : &'static str,
    lat : f32,
    lon : f32,
}

impl Display for City {
    fn fmt(&self, f: &mut Formatter) -> fmt::Result {
        let lat_c = if self.lat >= 0.0 {
            'N'
        } else {
            'S'
        };

        let lon_c =  if self.lon >= 0.0 {
            'E'
        } else {
            'W'
        };

        write!(f, "{} : {:.3}°{} {:.3}°{}", self.name, self.lat.abs(), lat_c,
                self.lon.abs(), lon_c)
    }
}

fn main() {
    let city = City {name : "Beijing", lat : 39.90469, lon : -116.40717};
    assert_eq!(format!("{}", city), "Beijing : 39.905°N 116.407°W");
    println!("{}", city);
}
