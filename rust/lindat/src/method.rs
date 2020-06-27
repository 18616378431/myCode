//!HTTP request method
use self::Inner::*;
use std::{error, fmt, str};

///Return Undefined method
#[derive(Debug)]
pub struct InvalidMethod<'a>(&'a str);

impl<'a> fmt::Display for InvalidMethod<'a> {
    fn fmt(&self, f : &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Invalid HTTP Method : {}", self.0)
    }
}

impl<'a> From<&'a str> for InvalidMethod<'a> {
    fn from(error : &'a str) -> Self {
        InvalidMethod(error)
    }
}

impl<'a> error::Error for InvalidMethod<'a> {

}

///Request method
///Contains Constants for mutiple HTTP headers:
///GET,HEAD
#[derive(Debug, Eq, PartialEq)]
pub struct Method(Inner);

///Get Head must be implemented unser HTTP/1.1
#[derive(Debug, Eq, PartialEq)]
enum Inner {
    Options,
    Get,
    Head,
    Post,
    Put,
    Delete,
    Trace,
    Connect,
}

impl Method {
    ///options
    pub const OPTIONS : Method = Method(Options);

    ///GET
    pub const GET : Method = Method(Get);

    ///HEAD
    pub const HEAD : Method = Method(Head);

    ///POST
    pub const POST : Method = Method(Post);

    ///PUT
    pub const PUT : Method = Method(Put);

    ///DELETE
    pub const DELETE : Method = Method(Delete);

    ///TRACE
    pub const TRACE : Method = Method(Trace);

    ///CONNECT
    pub const CONNECT : Method = Method(Connect);

    ///Return HTTP Method as Method object form a &str
    #[allow(clippy::should_implement_trait)]
    pub fn from_str(src : &str) -> Result<Method, InvalidMethod> {
        match src {
            "OPTIONS" => Ok(Method(Options)),
            "GET" => Ok(Method(Get)),
            "HEAD" => Ok(Method(Head)),
            "POST" => Ok(Method(Post)),
            "PUT" => Ok(Method(Put)),
            "DELETE" => Ok(Method(Delete)),
            "TRACE" => Ok(Method(Trace)),
            "CONNECT" => Ok(Method(Connect)),
            e => Err(InvalidMethod(e)),
        }
    }

    ///Return HTTP Method as &str from an object
    pub fn as_str(&self) -> &str {
        match self.0 {
            Options => "OPTIONS",
            Get => "GET",
            Head => "HEAD",
            Post => "POST",
            Put => "PUT",
            Delete => "DELETE",
            Trace => "TRACE",
            Connect => "CONNECT",
        }
    }
}

impl Default for Method {
    fn default() -> Method {
        Method::GET
    }
}
