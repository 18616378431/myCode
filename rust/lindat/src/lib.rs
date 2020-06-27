pub mod status;
pub mod method;
pub mod content;
pub mod request;
pub mod response;
pub mod threadpool;

use content::ContentType;
use method::Method;
use request::{get_request_line, parse_request_line, Request};
use response::response;
use status::StatusCode;

use log::{error, info};
use std::error::Error;
use std::io::{Read, Write};
use std::net::TcpStream;

///Handle TcpStream connection
#[allow(clippy::unused_io_amount)]
pub fn handle_connection(mut stream : TcpStream) -> Result<(), Box<dyn Error>> {
    let mut buffer = [0u8; 1024];

    stream.read(&mut buffer)?;

    let request_line = get_request_line(&buffer)?;
    info!("Request-Line : {}", &request_line);

    //Get Response from request_line
    let response = match parse_request_line(&request_line) {
        Ok(request) => response(&request),
        Err(e) => {
            error!("Bad Request : {}", e);
            Err(e)
        }
    };

    match response {
        Ok(mut response) => {
            info!("Response : {}", response);
            stream.write_all(&response.format_response())?;
            stream.flush()?;
        },
        Err(e) => error!("Response Error : {}", e),
    }

    Ok(())
}
