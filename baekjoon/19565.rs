use std::io;

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n);
    let n: i32 = n.trim().parse().unwrap();

    println!("{}", n * n + 1);

    for i in 1..=n {
        print!("{i} ");
        for j in i + 1..=n {
            print!("{i} {j} ");
        }
    }
    println!("1");
}
