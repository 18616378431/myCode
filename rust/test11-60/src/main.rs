//MPMC
use crossbeam::channel as channel;

fn main() {
    let (s, r) = channel::unbounded();
    crossbeam::scope(|scope| {
        scope.spawn(|scope| {
            s.send(1);
            r.recv().unwrap();
        });
        scope.spawn(|scope| {
            s.send(2);
            r.recv().unwrap();
        });
    });
}
