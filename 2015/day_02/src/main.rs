use std::fs::File;
use std::io::prelude::*;
use std::convert::TryInto;

fn main() -> std::io::Result<()> {
    let mut total_feet = 0;

    let mut file = File::open("input.txt")?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    contents = contents.trim().to_string();
    
    for line in contents.lines() {
        let [l, w, h]: [i32; 3] = parse(line).as_slice().try_into().ok().unwrap();
        total_feet += get_surface_area(l, w, h);
    }

    println!("Wrapping Paper: {}", total_feet);

    Ok(())
}

fn get_surface_area(l: i32, w: i32, h: i32) -> i32 {
    let sides = [l*w, w*h, h*l];
    let smallest_side = sides.iter().min().unwrap();
    let double_sides = sides.iter().map(|side| side * 2);
    let surface_area: i32 = double_sides.sum::<i32>() + smallest_side;
    surface_area
}

fn parse(sides_str: &str) -> Vec<i32> {
    let sides: Vec<i32> = sides_str
        .trim()
        .split('x')
        .map(|s| s.parse::<i32>().unwrap())
        .collect();
    sides 
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_get_surface_area() {
        assert_eq!(58, get_surface_area(2, 3, 4));
    }

    #[test]
    fn test_get_surface_area_2() {
        assert_eq!(43, get_surface_area(1, 1, 10));
    }

    #[test]
    fn test_sides_parser() {
        assert_eq!(vec![29, 13, 26], parse("29x13x26"));
    }
}
