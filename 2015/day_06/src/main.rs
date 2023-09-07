use std::fs::File;
use std::io::Read;

fn part_1() {

}

fn main() -> std::io::Result<()> {
    let mut file = File::open("input.txt")?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    contents = contents.trim().to_string();

    println!("{contents}");

    Ok(())
}
