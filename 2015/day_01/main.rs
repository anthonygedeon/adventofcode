use std::fs::File;
use std::io::prelude::*;

fn main() -> std::io::Result<()> {
    let mut input = File::open("input.txt")?;
    let mut contents = String::new();
    input.read_to_string(&mut contents)?;
    let cleaned_input = contents.trim();

    let floor = get_floor(cleaned_input);
    let pos   = get_pos(cleaned_input);

    println!("Floors: {}", floor);
    println!("Position: {}", pos);

    Ok(())
}

/// Part 1: Tally the total amount of instructions to execute
fn get_floor(instructions: &str) -> i32 {
    let mut floor = 0;
    for instr in instructions.chars() {
        match instr {
            '(' => floor += 1,  
            ')' => floor -= 1, 
            _ => (), 
        }
    }
    floor
}

/// Part 2: Get the position of when there are in the basement, basement = -1
fn get_pos(instructions: &str) -> i32 {
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

#[cfg(test)]
mod tests {
    use super::*; 

    /// Part 1
    #[test] 
    fn test_balanced_paren() {
        assert_eq!(0, get_floor("(())"));
    }

    #[test] 
    fn test_left_paren() {
        assert_eq!(3, get_floor("((("));
    }

    #[test] 
    fn test_right_paren() {
        assert_eq!(-3, get_floor(")))"));
    }

    #[test] 
    fn test_inbalanced_paren() {
        assert_eq!(3, get_floor("(()(()("));
    }
    
    /// Part 2
    #[test]
    fn test_get_pos() {
        assert_eq!(5, get_pos("()())"));
    }
}
