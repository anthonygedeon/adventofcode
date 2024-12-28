from typing import List
from operator import mul
from functools import reduce

def surface_area(l: int, w: int, h: int) -> int:
    return 2 * (l*w + w*h + h*l)

def smallest_side(l: int, w: int, h: int) -> int:
    return min(l * w, w * h, h*l)

def parse_dimensions(d: str) -> List[int]:
    return list(map(int, d.strip().split("x")))

def part_1(lines: List[str]) -> int:
    total: int = 0
    for line in lines:
        l, w, h = parse_dimensions(line)
        total += surface_area(l, w, h) + smallest_side(l, w, h)
    return total

def part_2(lines: List[str]) -> int:
    total: int = 0
    for line in lines:
        dimensions = parse_dimensions(line)
        dimensions.sort() 
        total += reduce(mul, dimensions, 1) + (2 * (dimensions[0] + dimensions[1]))
    return total

def main(test = False) -> None:
    if test:
        assert part_1(["2x3x4"]) == 58
        print("***Part 1 Test pass***")

        assert part_2(["2x3x4"]) == 34
        assert part_2(["1x1x10"]) == 14
        assert part_2(["2x3x4", "1x1x10"]) == 48
        print("***Part 2 Test pass***")
    else:
        with open("input.txt", "r") as f:
            content = f.readlines()
            print(part_1(content))
            print(part_2(content))

main(test = False)
