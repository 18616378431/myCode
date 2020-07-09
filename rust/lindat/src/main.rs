use lindat::handle_connection;
use lindat::threadpool::ThreadPool;
use log::{error, info};
use std::net::TcpListener;

fn main() {
    simple_logger::init().unwrap();
    info!("Starting Server...");

    let ip = "127.0.0.1:8594";

    let listener = TcpListener::bind(ip).expect("Unable to create listener");
    info!("Server Started On : {}{}", "http://", ip);

    let pool = ThreadPool::new(16);

    for stream in listener.incoming() {
        match stream {
            Ok(stream) => pool.execute(|| match handle_connection(stream){
                Ok(_) => (),
                Err(e) => error!("Error handling connection : {}", e),
            }),
            Err(e) => error!("Connection Failed : {}", e),
        }
    }
}