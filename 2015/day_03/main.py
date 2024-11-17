from typing import List

class Solution:
    def part_1(self, path: str) -> int:
        position: List[int] = [0, 0]
        houses: List[List[int]] = [[0, 0]]
        for d in path:
            match d:
                case '>': 
                    position[0] += 1
                case '<':
                    position[0] -= 1
                case '^':
                    position[1] += 1
                case 'v':
                    position[1] -= 1
            houses.append(position.copy())
        return len(set(map(tuple, houses)))

    def part_2(self, path: str) -> int:
        toggle: bool = True
        s_position: List[int] = [0, 0]
        r_position: List[int] = [0, 0]
        s_houses: List[List[int]] = [[0, 0]]
        r_houses: List[List[int]] = [[0, 0]]
        for d in path:
            match d:
                case '>': 
                    if toggle:
                        s_position[0] += 1
                    else: 
                        r_position[0] += 1
                case '<':
                    if toggle:
                        s_position[0] -= 1
                    else: 
                        r_position[0] -= 1
                case '^':
                    if toggle:
                        s_position[1] += 1
                    else: 
                        r_position[1] += 1
                case 'v':
                    if toggle:
                        s_position[1] -= 1
                    else: 
                        r_position[1] -= 1

            if toggle:
                s_houses.append(s_position.copy())
            else:
                r_houses.append(r_position.copy())

            toggle = not toggle
        set_s = set(map(tuple, s_houses))
        set_r = set(map(tuple, r_houses))

        return len(set_s.union(set_r))

    def test_part_1(self) :
        assert self.part_1(">") == 2
        assert self.part_1("^>v<") == 4
        assert self.part_1("^v^v^v^v^v") == 2

    def test_part_2(self) -> None:
        assert self.part_2("^v") == 3
        assert self.part_2("^>v<") == 3
        assert self.part_2("^v^v^v^v^v") == 11

def main(test: bool = False) -> None:
    s = Solution()

    if test:
        s.test_part_1()
        print("***(part_1)Test Passed***")

        s.test_part_2()
        print("***(part_2)Test Passed***")
    else:
        with open("input.txt", "r") as f:
            content = f.read()
            print(s.part_1(content))
            print(s.part_2(content)) 

main()

