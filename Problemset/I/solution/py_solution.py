n, q = map(int, input().split())
answer = [0] * n
constraint = [tuple(map(int, input().split())) for _ in range(q)]
for i in range(q):
    constraint[i] = (constraint[i][0] - 1, constraint[i][1], constraint[i][2])

ed = [[] for _ in range(2 * n + 2)]
mark = [0] * (n + 1)
for l, r, v in constraint:
    if v == 1:
        ed[2 * r].append(2 * l)
        ed[2 * l].append(2 * r)
        ed[2 * r + 1].append(2 * l + 1)
        ed[2 * l + 1].append(2 * r + 1)
        mark[l] += 1
        mark[r] -= 1
    elif v == 2:
        ed[2 * r].append(2 * l + 1)
        ed[2 * l].append(2 * r + 1)
        ed[2 * r + 1].append(2 * l)
        ed[2 * l + 1].append(2 * r)
        mark[l] += 1
        mark[r] -= 1

ok = True

for i in range(n):
    mark[i + 1] += mark[i]
mark.insert(0, 0)
mark.pop()
for i in range(len(mark)):
    mark[i] = bool(mark[i])
for i in range(n):
    mark[i + 1] += mark[i]

for l, r, v in constraint:
    if v == 0 and mark[r] - mark[l] == r - l:
        ok = False


def color(ed):
    n = len(ed)
    visit = [0] * n
    color = [-1] * n
    stack = []
    order = []
    scc = 0

    for i in range(n):
        if visit[i] == 0:
            stack.append(i)
            while stack:
                x = stack[-1]
                if visit[x] == 0:
                    visit[x] = 1
                    for y in ed[x]:
                        if visit[y] == 0:
                            stack.append(y)
                else:
                    stack.pop()
                    order.append(x)

    visit = [0] * n
    for i in reversed(order):
        if visit[i] == 0:
            stack.append(i)
            while stack:
                x = stack.pop()
                if visit[x] == 0:
                    visit[x] = 1
                    color[x] = scc
                    for y in ed[x]:
                        if visit[y] == 0:
                            stack.append(y)
            scc += 1

    return color


color = color(ed)


def check(color, n):
    for i in range(n + 1):
        if color[2 * i] == color[2 * i + 1]:
            return True
    return False


if check(color, n):
    ok = False


def assign(answer, mark, n, color):
    for i in range(n):
        if mark[i + 1] - mark[i] == 0:
            continue
        f = color[2 * i] < color[2 * i + 1]
        g = color[2 * (i + 1)] < color[2 * (i + 1) + 1]
        if f != g:
            answer[i] = 2
        else:
            answer[i] = 1


assign(answer, mark, n, color)

if not ok:
    answer = [-1] * n

for i in range(n):
    print(answer[i], end=" ")
print()
