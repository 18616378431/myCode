//可见性
pub mod outer_mod {
    pub(self) fn outer_mod_fn() {}

    pub mod inner_mod {
        //use 导入外部函数
        use crate::outer_mod::outer_mod_fn;
        //对指定模块可见
        pub (in crate::outer_mod) fn outer_mod_visible_fn() {}
        //对整个crate可见
        pub (crate) fn crate_visible_fn() {}
        //outer_mod内部可见
        pub (super) fn super_mod_visible_fn() {
            //访问同一个模块函数
            inner_mod_visible_fn();
            //访问父模块需要使用::
            outer_mod_fn();
        }
        //inner_mod内部可见
        pub (self) fn inner_mod_visible_fn() {}
    }

    pub fn foo() {
        inner_mod::outer_mod_visible_fn();
        inner_mod::crate_visible_fn();
        inner_mod::super_mod_visible_fn();
        //无法使用inner_mod私有函数
        // inner_mod::inner_mod_visible_fn();
    }
}

fn bar() {
    //对整个crate可见
    outer_mod::inner_mod::crate_visible_fn();
    //只对outer_mod可见
    // outer_mod::inner_mod::super_mod_visible_fn();
    //只对outer_mod可见
    // outer_mod::inner_mod::outer_mod_visible_fn();
    //通过foo函数调用内部细节
    outer_mod::foo();
}
fn main() {
    bar();
}
