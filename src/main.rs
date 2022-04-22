use std::thread;
use std::time::Duration;

mod blender {}
mod fsx {}

fn main() {
    let r = json::parse(r#"{"abc":"def"}"#);
    println!("Hello, world! {:?}", r.unwrap()["abc"]);

    let f = thread::spawn(|| {
        for i in 1..10 {
            thread::sleep(Duration::from_secs(1));
            println!("{}", i);
        }
    });

    f.join().unwrap();
}
