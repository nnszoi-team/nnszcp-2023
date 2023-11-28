from random import randint

def gen(a: list) -> None:
    for r in a:
        print(randint(0, r), end = " ")
    print()

if __name__ == "__main__":

    gen([120, 120, 120, 100, 100, 120, 740])
    n = randint(99900, 100000)
    print(n, end = " ")
    print(randint(0, n))
    for i in range(n):
        gen([120, 120, 120, 100, 100, 120, 60])
