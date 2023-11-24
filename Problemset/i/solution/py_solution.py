from collections import deque


class Spfa:
    def __init__(self, n: int):
        self.n = n
        self.ed = [[] for _ in range(n + 1)]
        self.dis = [0x3F3F3F3F] * (n + 1)
        self.vis = [False] * (n + 1)

    def add_edge(self, u: int, v: int, w: int):
        self.ed[u].append((v, w))

    def spfa(self, s: int):
        self.dis[s] = 0
        self.vis[s] = True
        q = deque([s])
        while q:
            x = q.popleft()
            self.vis[x] = False
            for i, w in self.ed[x]:
                if self.dis[i] > self.dis[x] + w:
                    self.dis[i] = self.dis[x] + w
                    if not self.vis[i]:
                        q.append(i)
                        self.vis[i] = True


class Twosat:
    def __init__(self, n: int):
        self.count = 0
        self.color_count = 0
        self.n = n
        self.vis = [False] * n
        self.id = [0] * n
        self.low = [0] * n
        self.color = [0] * n
        self.ed = [[] for _ in range(n)]
        self.stack = []

    def add_edge(self, u: int, v: int):
        self.ed[u].append(v)
        self.ed[v].append(u)

    def tarjan(self, x: int):
        stack = [(x, 0)]
        while stack:
            x, idx = stack[-1]
            if idx == 0:
                self.stack.append(x)
                self.vis[x] = True
                self.id[x] = self.low[x] = self.count + 1
                self.count += 1
            remove = True
            for i in range(idx, len(self.ed[x])):
                stack[-1] = (x, i + 1)
                y = self.ed[x][i]
                if self.id[y] == 0:
                    stack.append((y, 0))
                    remove = False
                    break
                elif self.vis[y]:
                    self.low[x] = min(self.low[x], self.id[y])
            if remove:
                stack.pop()
                if self.id[x] == self.low[x]:
                    self.color_count += 1
                    while True:
                        top = self.stack.pop()
                        self.vis[top] = False
                        self.color[top] = self.color_count
                        if top == x:
                            break

    def twosat(self):
        for i in range(self.n):
            if self.id[i] == 0:
                self.tarjan(i)


def main():
    n, q = map(int, input().split())
    answer = [1] * (n + 1)
    cst = [[] for _ in range(4)]

    for _ in range(q):
        l, r, v = map(int, input().split())
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
            answer[i] = 2

    H = Twosat(2 * (n + 1))

    for l, r in cst[1]:
        H.add_edge(2 * (l - 1), 2 * r)
        H.add_edge(2 * (l - 1) + 1, 2 * r + 1)

    for l, r in cst[3]:
        H.add_edge(2 * (l - 1) + 1, 2 * r)
        H.add_edge(2 * (l - 1), 2 * r + 1)

    H.twosat()

    for i in range(2, 2 * n + 1, 2):
        if answer[i // 2] == 2:
            continue
        f1 = H.color[i] < H.color[i + 1]
        f2 = H.color[i - 2] < H.color[i - 1]
        if f1 == f2:
            answer[i // 2] = 1
        else:
            answer[i // 2] = 3

    print(" ".join(map(str, answer[1 : n + 1])))


if __name__ == "__main__":
    main()
