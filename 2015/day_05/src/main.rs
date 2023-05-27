use std::fs::File;
use std::io::*;

fn main() -> Result<()> {
    let mut file = File::open("input.txt")?;
    let mut input = String::new();
    file.read_to_string(&mut input)?;

    println!("{input}");

    let mut nice_strings = 0;
    for word in input.split_terminator("\n") {
        if part_1(word) {
            nice_strings += 1;
        }
    }
    println!("{nice_strings}");

    let mut nice_strings = 0;
    for word in input.split_terminator("\n") {
        if part_2(word) {
            nice_strings += 1;
        }
    }
    println!("{nice_strings}");

    Ok(())
}
fn part_1(word: &str) -> bool {
    let word = word.to_lowercase();
    let mut nice_word = false;

    if word
        .chars()
        .filter(|&c| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        .collect::<Vec<char>>()
        .len()
        >= 3
    {
        nice_word = true;
    }

    if nice_word == false {
        return false;
    }

    for pair in word.as_bytes().windows(2) {
        if pair.len() == 2 {
            if pair[0] == pair[1] {
                nice_word = true;
                break;
            } else {
                nice_word = false;
            }
        }
    }

    for pair in word.as_bytes().windows(2) {
        if pair.len() == 2 {
            let w = pair
                .to_vec()
                .iter()
                .map(|&c| char::from(c))
                .collect::<String>();
            // println!("{}", w);
            if w == "ab" || w == "cd" || w == "pq" || w == "xy" {
                nice_word = false;
            }
        }
    }

    nice_word
}

fn part_2(word: &str) -> bool {
    let mut result = false;

    'a: for (i, pair_a) in word.as_bytes().windows(2).enumerate() {
        for (j, pair_b) in word.as_bytes().windows(2).skip(2).enumerate() {
            if j >= i {
                if pair_a == pair_b {
                    result = true;
                    break 'a;
                }
            }
        }
    }

    if result == false {
        return false;
    }

    for i in 0..word.len() {
        if (i + 2) >= word.len() {
            break;
        }
        let letter_1 = word.chars().nth(i).unwrap();
        let letter_2 = word.chars().nth(i + 2).unwrap();
        if letter_1 == letter_2 {
            result = true;
            break;
        } else {
            result = false;
        }
    }

    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_contains_vowels_doubles_and_black_listed_letters() {
        assert_eq!(part_1("ugknbfddgicrmopn"), true)
    }
    #[test]
    fn test_tricky_nice_word() {
        assert_eq!(part_1("aaa"), true)
    }
    #[test]
    fn test_naughty_word_1() {
        assert_eq!(part_1("jchzalrnumimnmhp"), false)
    }
    #[test]
    fn test_naughty_word_2() {
        assert_eq!(part_1("haegwjzuvuyypxyu"), false)
    }
    #[test]
    fn test_naughty_word_3() {
        assert_eq!(part_1("dvszwmarrgswjxmb"), false)
    }

    #[test]
    fn test_better_model_1() {
        assert_eq!(part_2("qjhvhtzxzqqjkmpb"), true);
    }

    #[test]
    fn test_better_model_2() {
        assert_eq!(part_2("xxyxx"), true);
    }

    #[test]
    fn test_better_model_3() {
        assert_eq!(part_2("uurcxstgmygtbstg"), false);
    }

    #[test]
    fn test_better_model_4() {
        assert_eq!(part_2("ieodomkazucvgmuy"), false);
    }
}
