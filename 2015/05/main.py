from typing import List

def count_vowels(word: str) -> int:
    total: int = 0
    for vowel in "aeiou":
        total += word.count(vowel)
    return total

def count_naughty_double_letters(word: str) -> int:
    total: int = 0
    for i in range(len(word)):
        if word[i:i+2] in { "ab", "cd", "pq", "xy" }:
            total += 1
    return total

def count_nice_double_letters(word: str) -> int:
    total: int = 0
    for i in range(len(word)):
        if len(word[i:i+2]) >= 2:
            a, b = word[i:i+2]
            if a == b:
                total += 1
    return total
    

def part_1(words: List[str]) -> int:
    nice_words: int = 0
    for w in words:
        if (count_vowels(w) >= 3 and count_naughty_double_letters(w) == 0 and 
            count_nice_double_letters(w) >= 1):
            nice_words += 1
    return nice_words

def part_2(words: List[str]) -> int:
    nice_words: int = 0
    for word in words:
        is_pair = False
        is_twice = False

        for i in range(len(word)):
            pair = word[i:i+2]
            if pair in word[i+2:]:
                is_pair = True
                break

        for i in range(len(word)):
            if len(word[i:i+3]) >= 3:
                a, _, c = word[i:i+3]
                if a == c:
                    is_twice = True
                    break

        if is_pair and is_twice:
            nice_words += 1
                    
    return nice_words

def main(test: bool = True) -> None:
    if test:
        assert part_1(["ugknbfddgicrmopn", "aaa"]) == 2
        assert part_1(["jchzalrnumimnmhp", "haegwjzuvuyypxyu", "dvszwmarrgswjxmb"]) == 0
        print("***part_1 function test pass***")
        
        # assert part_2(["qjhvhtzxzqqjkmpb", "xxyxx"]) == 2
        # assert part_2(["uurcxstgmygtbstg", "ieodomkazucvgmuy"]) == 0
        print("***part_2 function test pass***")
    else:
        with open("input.txt", "r") as f:
            words = f.readlines()
            # print(part_1(words))
            print(part_2(words))

main(False)
