use std::fs::File;
use std::io::prelude::*;

fn part_1(instructions: &str) -> isize {
    instructions.chars().fold(0, |mut floor, instruction| {
        match instruction {
            '(' => floor += 1,
            ')' => floor -= 1,
            _ => unreachable!(),
        };
        floor
    })
}

fn part_2(instructions: &str) -> isize {
    let mut pos = 0;
    let mut count = 0;
    for instr in instructions.chars() {
        count += 1;
        match instr {
            '(' => pos += 1,
            ')' => pos -= 1,
            _ => (),
        }
        if pos == -1 {
            break;
        }
    }
    count
}

fn main() -> std::io::Result<()> {
    let mut input = File::open("input.txt")?;
    let mut contents = String::new();
    input.read_to_string(&mut contents)?;

    let contents = contents.trim();

    let floor = part_1(contents);
    let position = part_2(contents);

    println!("Part 1: {floor} Part 2: {position}");

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_balanced_paren() {
        assert_eq!(0, part_1("(())"));
    }

    #[test]
    fn test_left_paren() {
        assert_eq!(3, part_1("((("));
    }

    #[test]
    fn test_right_paren() {
        assert_eq!(-3, part_1(")))"));
    }

    #[test]
    fn test_inbalanced_paren() {
        assert_eq!(3, part_1("(()(()("));
    }

    #[test]
    fn test_get_pos() {
        assert_eq!(5, part_2("()())"));
    }
}
