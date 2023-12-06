from bisect import bisect_right

class Bit:
    
    def __init__(self, n: int) -> None:
        self.n = n
        self.bit = [0] * (n + 1)
    
    def add(self, idx: int) -> None:
        while 0 < idx <= self.n:
            self.bit[idx] += 1
            idx += idx & -idx
    
    def query(self, idx: int) -> int:
        res = 0
        while idx > 0:
            res += self.bit[idx]
            idx -= idx & -idx
        return res


if __name__ == "__main__":

    n = int(input())
    a = [ int(i) for i in input().split() ]
    b = sorted(list(set(a)))

    res = 0
    for i in range(n):
        if a[i] <= a[0]:
            continue
        res += 1
        a[0], a[i] = a[i], a[0]
    
    m = len(b)
    bit = Bit(m)
    bit.add(m)
    v = [False] * (m + 1)
    v[m] = True

    for i in range(1, n):
        idx = bisect_right(b, a[i])
        res += bit.query(m) - bit.query(idx)
        if v[idx]:
            continue
        bit.add(idx)
        v[idx] = True

    print(f"YES\n{res}")
