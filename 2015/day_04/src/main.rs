use crypto::digest::Digest;
use crypto::md5::Md5;

fn main() {
    println!(
        "{}",
        mine_advent_coins("ckczppom", |input| input.starts_with("00000"))
    );
    println!(
        "{}",
        mine_advent_coins("ckczppom", |input| input.starts_with("000000"))
    );
}

fn mine_advent_coins<F>(key: &str, check_prefix: F) -> u64
where
    F: Fn(&str) -> bool,
{
    let mut md5 = Md5::new();

    for i in 0..u64::MAX {
        md5.input_str(&format!("{}{}", key, i));

        let mut buffer = [0; 16];
        md5.result(&mut buffer);

        if check_prefix(&md5.result_str()) {
            return i;
        }

        md5.reset();
    }

    0
}

#[cfg(test)]
mod tests {
    use super::*;

    fn start_mining(input: &str) -> bool {
        input.starts_with("00000")
    }

    #[test]
    fn test_simple_secret_key() {
        assert_eq!(mine_advent_coins("abcdef", start_mining), 609043);
    }

    #[test]
    fn test_secret_key() {
        assert_eq!(mine_advent_coins("pqrstuv", start_mining), 1048970);
    }
}
