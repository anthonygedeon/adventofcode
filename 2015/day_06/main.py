from enum import Enum
from typing import Dict, List
import re
import pytest

def part_1(grid: List[List[int]], instructions: List[str]) -> int:
    for instr in instructions:
        state, x1, y1, x2, y2 = parse_instructions(instr)
        for x in range(x1, x2):
            for y in range(y1, y2):
                grid[x][y] ^= state
     
    lit: int = 0
    for row in grid:
        lit += sum(row)
    return lit



# def part_1() -> int:
#     pass

def parse_instructions(instruction: str) -> List[int]:
    state, x1, y1, x2, y2 = re.findall(r"(on|off|\d+)", instruction)
    toggle: int = 1 if state == "on" else 0 
    return [toggle, int(x1), int(y1), int(x2), int(y2)]

def main() -> None:
    grid: List[List[int]] = [[0 for _ in range(999)] for _ in range(999)]
    with open("input.txt", "r") as f:
        content = f.readlines()
        part_1(grid, content)
    pass

main()
