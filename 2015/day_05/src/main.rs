fn main() {
    println!("{}", part_1("www"));
    println!("{}", part_2("www"));
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

    println!(
        "{:?}",
        word.chars()
            .filter(|&c| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            .collect::<Vec<char>>()
    );

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
            let w = format!("{:?}", pair);
            if w != "ab" || w != "cd" || w != "pq" || w != "xy" {
                nice_word = true;
            } else {
                nice_word = false;
            }
        }
    }

    nice_word
}

fn part_2(word: &str) -> bool {
    unimplemented!()
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
}
