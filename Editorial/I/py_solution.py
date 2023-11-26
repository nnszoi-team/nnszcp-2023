from math import inf
from collections import deque


class Spfa:

    def __init__(self, n: int):
        self.n = n
        self.edge = [[] for _ in range(n + 1)]
        self.dis = [inf] * (n + 1)
        self.inq = [False] * (n + 1)

    def add_edge(self, u: int, v: int, w: int) -> None:
        self.edge[u].append((v, w))

    def spfa(self, s: int) -> None:
        self.dis[s] = 0
        self.inq[s] = True
        q = deque([s])
        while q:
            u = q.popleft()
            self.inq[u] = False
            for v, w in self.edge[u]:
                if self.dis[v] <= self.dis[u] + w:
                    continue
                self.dis[v] = self.dis[u] + w
                if not self.inq[v]:
                    q.append(v)
                    self.inq[v] = True


class Twosat:

    def __init__(self, n: int):
        self.count = 0
        self.color_count = 0
        self.n = n
        self.ins = [False] * n
        self.dfn = [0] * n
        self.low = [0] * n
        self.color = [0] * n
        self.edge = [[] for _ in range(n)]
        self.stack = []

    def add_edge(self, u: int, v: int) -> None:
        self.edge[u].append(v)
        self.edge[v].append(u)

    def tarjan(self, root: int) -> None:
        stack = [(root, 0)]
        while stack:
            u, idx = stack[-1]
            if idx == 0:
                self.stack.append(u)
                self.ins[u] = True
                self.count += 1
                self.dfn[u] = self.low[u] = self.count
            
            remove = True
            for i in range(idx, len(self.edge[u])):
                stack[-1] = (u, i + 1)
                v = self.edge[u][i]
                if self.dfn[v] == 0:
                    stack.append((v, 0))
                    remove = False
                    break
                elif self.ins[v]:
                    self.low[u] = min(self.low[u], self.dfn[v])
            
            if not remove:
                continue

            stack.pop()
            if self.dfn[u] == self.low[u]:
                self.color_count += 1
                top = -1
                while top != u:
                    top = self.stack.pop()
                    self.ins[top] = False
                    self.color[top] = self.color_count

    def twosat(self) -> None:
        for root in range(self.n):
            if self.dfn[root] == 0:
                self.tarjan(root)


if __name__ == "__main__":

    n, q = [int(i) for i in input().split()]
    ans = [1] * (n + 1)
    cst = [[] for _ in range(4)]

    for i in range(q):
        l, r, v = [int(i) for i in input().split()]
        cst[v].append((l, r))

    G = Spfa(n)

    for i in range(1, n + 1):
        G.add_edge(i - 1, i, 1)
        G.add_edge(i, i - 1, 0)
    for l, r in cst[0]:
        G.add_edge(r, l - 1, -2)
    for l, r in cst[1]:
        G.add_edge(r, l - 1, 0)
        G.add_edge(l - 1, r, 0)
    for l, r in cst[2]:
        G.add_edge(l - 1, r, 1)
        G.add_edge(r, l - 1, -1)
    for l, r in cst[3]:
        G.add_edge(r, l - 1, 0)
        G.add_edge(l - 1, r, 0)

    G.spfa(0)

    for i in range(1, n + 1):
        diff = G.dis[i] - G.dis[i - 1]
        if diff == 1:
            ans[i] = 2

    H = Twosat(2 * (n + 1))

    for l, r in cst[1]:
        H.add_edge(2 * (l - 1), 2 * r)
        H.add_edge(2 * (l - 1) + 1, 2 * r + 1)

    for l, r in cst[3]:
        H.add_edge(2 * (l - 1) + 1, 2 * r)
        H.add_edge(2 * (l - 1), 2 * r + 1)

    H.twosat()

    for i in range(2, 2 * n + 1, 2):
        if ans[i >> 1] == 2:
            continue
        f1 = H.color[i] < H.color[i + 1]
        f2 = H.color[i - 2] < H.color[i - 1]
        ans[i >> 1] = 1 if f1 == f2 else 3

    for i in ans[1 : n + 1]:
        print(i, end = " ")
