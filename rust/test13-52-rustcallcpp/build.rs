extern crate cc;

fn main() {
    cc::Build::new()
    .cpp(true)
    .warnings(true)
    .flag("-Wall")
    .flag("-std=c++14")
    .flag("-c")
    .file("cpp_src/sorting.cpp")
    .compile("sorting");
}