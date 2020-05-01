//! 块级文档
//! this is documentation for the `csv_challenge` lib crate
//! 
//! Usage:
//! ```
//! use test10_48csv_challenge::{
//!     Opt,
//!     {load_csv, write_csv},
//!     replace_column,
//! };
//! ```
mod opt;
mod err;
mod core;

//重新导出
pub use self::opt::Opt;
pub use self::core::{
    read::{load_csv, write_csv},
    write::replace_column,
};
