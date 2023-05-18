use std::{
    collections::{HashMap, HashSet},
    fs::File,
    io::prelude::*,
};

fn main() {
    let mut file = File::open("input.txt").expect("could not find file");
    let mut buffer = String::new();
    file.read_to_string(&mut buffer).unwrap();

    println!("Part 1: {}", part_1(&buffer));
    println!("Part 2: {}", part_2(&buffer));
}

fn part_1(directions: &str) -> usize {
    let mut houses = vec![(0, 0)];
    for direction in directions.chars() {
        let position = houses
            .last()
            .and_then(|(x, y)| match direction {
                '>' => Some((x + 1, *y)),
                '<' => Some((x - 1, *y)),
                '^' => Some((*x, y + 1)),
                'v' => Some((*x, y - 1)),
                _ => unreachable!(),
            })
            .unwrap();
        houses.push(position);
    }

    houses
        .into_iter()
        .collect::<HashSet<(isize, isize)>>()
        .len()
}

fn part_2(directions: &str) -> usize {
    #[derive(Hash, PartialEq, Eq, Debug)]
    enum Switch {
        Santa,
        RoboSanta,
    }
    let mut houses: HashMap<Switch, Vec<(isize, isize)>> = HashMap::new();

    houses.insert(Switch::Santa, vec![(0, 0)]);
    houses.insert(Switch::RoboSanta, vec![(0, 0)]);

    let mut state = Switch::Santa;

    for direction in directions.chars() {
        let position = houses
            .get(&state)
            .unwrap()
            .last()
            .and_then(|(x, y)| match direction {
                '>' => Some((x + 1, *y)),
                '<' => Some((x - 1, *y)),
                '^' => Some((*x, y + 1)),
                'v' => Some((*x, y - 1)),
                _ => unreachable!(),
            })
            .unwrap();
        houses.get_mut(&state).unwrap().push(position);
        match state {
            Switch::Santa => state = Switch::RoboSanta,
            Switch::RoboSanta => state = Switch::Santa,
        }
    }

    let mut lists = Vec::new();

    let santa_houses = houses.get(&Switch::Santa).unwrap().clone();
    let robo_houses = houses.get(&Switch::RoboSanta).unwrap().clone();
    lists.push(santa_houses);
    lists.push(robo_houses);
    let lists = lists.into_iter().flatten().collect::<Vec<(isize, isize)>>();

    lists.into_iter().collect::<HashSet<(isize, isize)>>().len()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_deliver_to_two_houses() {
        assert_eq!(part_1(">"), 2);
    }

    #[test]
    fn test_deliver_to_four_houses() {
        assert_eq!(part_1("^>v<"), 4);
    }

    #[test]
    fn test_deliver_to_houses() {
        assert_eq!(part_1("^v^v^v^v^v"), 2);
    }

    #[test]
    fn test_deliver_to_two_houses_robo() {
        assert_eq!(part_2("^v"), 3);
    }

    #[test]
    fn test_deliver_to_four_houses_robo() {
        assert_eq!(part_2("^>v<"), 3);
    }

    #[test]
    fn test_deliver_to_houses_robo() {
        assert_eq!(part_2("^v^v^v^v^v"), 11);
    }
}
