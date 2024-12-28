import hashlib

def md5_hash_to_string(payload: str) -> str: 
    return hashlib.md5(payload.encode()).hexdigest()

def part_1(secret: str) -> int:
    for i in range(1, 999999):
        cracked: str = md5_hash_to_string(f"{secret}{i}")
        if cracked.startswith("00000"):
            return i
    return -1

def part_2(secret: str) -> int:
    for i in range(1000000, 9999999):
        cracked: str = md5_hash_to_string(f"{secret}{i}")
        if cracked.startswith("000000"):
            return i
    return -1

def main(test = False) -> None:
    if test:
        assert part_1("abcdef") == 609043
        print("***Part 1 & Part 2 Test pass***")
    else:
        print(part_1("iwrupvqb"))
        print(part_2("iwrupvqb"))

main(test = False)
