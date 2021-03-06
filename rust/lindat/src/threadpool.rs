//!ThreadPool implementation
use log::info;
use std::sync::{mpsc, Arc, Mutex};
use std::thread;

enum Message {
    NewJob(Job),
    Terminate,
}

/// ThreadPool Contains Workers & Senders
/// mpsc Senders sending Message
pub struct ThreadPool {
    workers : Vec<Worker>,
    sender : mpsc::Sender<Message>,
}

trait FnBox {
    fn call_box(self : Box<Self>);
}

impl<F : FnOnce()> FnBox for F {
    fn call_box(self : Box<F>) {
        (*self)()
    }
}

type Job = Box<dyn FnBox + Send + 'static>;

struct Worker {
    id : usize,
    thread : Option<thread::JoinHandle<()>>,
}

impl Worker {
    fn new(id :usize, receiver : Arc<Mutex<mpsc::Receiver<Message>>>) -> Worker {
        //create JoinHandle<()> instance
        let thread = thread::spawn(move || {
            loop {
                //acquire mutex, panic if it's poisoned(thread panic while holding lock)
                //if all is good, receive Job from channel
                let message = receiver
                    .lock()
                    .expect("Poisoned Thread")
                    .recv()
                    .expect("Thread Holding send has shutdown");
                //mutex make sure only a single thread can make a request for a job

                match message {
                    Message::NewJob(job) => {
                        info!("Worker id : {} received job;executing.", id);
                        job.call_box();
                    },
                    Message::Terminate => {
                        println!("Worker id : {} was told to terminate.", id);
                        break;
                    }
                }
            }
        });
        Worker {
            id,
            thread : Some(thread),
        }
    }
}

impl ThreadPool {
    ///create new thread pool
    pub fn new(size : usize) -> ThreadPool {
        assert!(size > 0);

        let (sender, receiver) = mpsc::channel();

        let receiver = Arc::new(Mutex::new(receiver));

        let mut workers = Vec::with_capacity(size);

        for id in 0..size {
            workers.push(Worker::new(id, Arc::clone(&receiver)));
        }

        ThreadPool {
            workers,
            sender
        }
    }

    /// execute job
    pub fn execute<F>(&self, f : F)
    where
        F : FnOnce() + Send + 'static,
    {
        let job = Box::new(f);

        self.sender.send(Message::NewJob(job)).unwrap();
    }
}

impl Drop for ThreadPool {
    fn drop(&mut self) {
        info!("Sending terminate message to all workers");

        for _ in &mut self.workers {
            self.sender.send(Message::Terminate).unwrap();
        }

        info!("Shutting down all workers.");

        for worker in &mut self.workers {
            info!("Shutting down worker id : {}", worker.id);

            if let Some(thread) = worker.thread.take() {
                thread.join().unwrap();
            }
        }
    }
}
