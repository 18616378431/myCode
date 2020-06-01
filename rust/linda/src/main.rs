use log::{error, info};
use std::net::TcpListener;
use std::path::Path;
use std::fmt;
use std::fs;
use std::net::TcpStream;
use std::io::{Read, Write};

//请求行
struct Request<'a> {
    method : &'a str,
    uri : &'a Path,
    http_version : &'a str,
}

const ROOT : &str = "/Users/wangjiankang/Downloads/rust/linda/htdocs";

fn main() {
    simple_logger::init().unwrap();
    info!("Starting server");
    
    let ip = "127.0.0.1:8594";

    let listener = TcpListener::bind(ip).expect("Unable to create listener!");
    info!("Server started on : {}{}", "http://", ip);

    for stream in listener.incoming() {
        match stream {
            Ok(stream) => match handle_connection(stream) {
                Ok(_) => (),
                Err(e) => error!("Error handling connection : {}", e),
            },
            Err(e) => error!("Connection failed : {}", e),
        }
    }
}

/**
 * 处理请求
 */
fn handle_connection<'a>(mut stream : TcpStream) -> Result<(), &'a str> {
    //512字节缓冲区
    let mut buffer = [0; 512];

    //将流写入缓存
    stream.read(&mut buffer).unwrap();

    let request = String::from_utf8_lossy(&buffer[..]);
    let request_line = request.lines().next().unwrap();

    match parse_request_line(&request_line) {
        Ok(request) => {
            info!("Request Struct : {}", &request);
            info!("uri : {}", request.uri.display());
            // let uri = request.uri.display();

            // let contents = fs::read_to_string(format!("{}{}", ROOT, "index.html")).unwrap();
            let file_path = format!("{}/{}", ROOT, "index.html");
            let contents = fs::read_to_string(file_path).unwrap();
            let content_length = contents.len();
            info!("File Size : {}", content_length);
            let header = format!("HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\nContent-Length: {}\r\n\r\n", content_length);
            let response = format!("{}{}", header, contents);

            info!("Response : \n{}", &response);
            stream.write(response.as_bytes()).unwrap();
            stream.flush().unwrap();
        },
        Err(e) => error!("Badly formatted request : {}", e),
    }

    Ok(())
}

/**
 * 解析请求行
 */
fn parse_request_line(request : &str) -> Result<Request, &str> {
    let mut parts = request.split_whitespace();

    let method = parts.next().ok_or("Method not specified")?;
    //Only GET
    if method != "GET" {
        Err("Unsupported method")?;
    }

    let uri = Path::new(parts.next().ok_or("URI not specified")?);
    let norm_uri = uri.to_str().expect("Invalid unicode");
    let resource_path = format!("{}{}", ROOT, norm_uri);

    if !Path::new(&resource_path).exists() {
        info!("Requested resource does not exist, {}", &resource_path);
        Err("Requested resource does not exist")?;
    }

    let http_version = parts.next().ok_or("HTTP version not specified")?;
    if http_version != "HTTP/1.1" {
        Err("Unsupported HTTP version, use HTTP/1.1")?;
    }

    Ok(Request {
        method,
        uri,
        http_version,
    })
}

//实现Display
impl<'a> fmt::Display for Request<'a> {
    fn fmt(&self, f : &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} {} {}\r\n", self.method, self.uri.display(), self.http_version)
    }
}

