def part_1(chars: str) -> int:
    floor: int = 0
    for ch in chars:
        match ch:
            case '(': floor += 1
            case ')': floor -= 1
    return floor

def part_2(chars: str) -> int:
    floor: int = 0
    for count, ch in enumerate(chars):
        if floor == -1: return count
        match ch:
            case '(': floor += 1
            case ')': floor -= 1
    return -1

def main(test = False) -> None:
    if test:
        assert part_1("(())") == 0
        assert part_1("()()") == 0
        assert part_1("(((") == 3
        assert part_1("(()(()(") == 3
        assert part_1("))(((((") == 3
        assert part_1("())") == -1
        assert part_1("))(") == -1
        assert part_1(")))") == -3
        assert part_1(")())())") == -3
        print("**part_1 tests pass**")
        
        assert part_2(")") == 1
        assert part_2("()())") == 5
        print("**part_2 tests pass**")
    else:
        with open("input.txt", "r") as f:
            content = f.read()
            print(part_1(content))
            print(part_2(content))

main(test = False)
