from fractions import Fraction


class Point:
    def __init__(self, x=Fraction(0), y=Fraction(0)):
        self.x = x
        self.y = y

    def __eq__(self, other) -> bool:
        return self.x == other.x and self.y == other.y

    def __lt__(self, other) -> bool:
        return self.x < self.x if self.x != other.x else self.y < self.y

    def __hash__(self) -> int:
        return int(self.x * int(1e50) + self.y)


class Line:
    def __init__(self, A: Point, B: Point):
        self.a = A.y - B.y
        self.b = B.x - A.x
        self.c = B.y * A.x - B.x * A.y

    def __xor__(self, other) -> Point:
        return Point(
            Fraction(
                (self.b * other.c - self.c * other.b)
                / (self.a * other.b - self.b * other.a)
            ),
            Fraction(
                (self.a * other.c - self.c * other.a)
                / (self.b * other.a - self.a * other.b)
            ),
        )


p, a, b, c, d = map(int, input().split())

answer = []
ref = []
list = {}


def draw_op1(x, y):
    if (Point(Fraction(x, 1), Fraction(y, 1))) in list:
        return Point(Fraction(x, 1), Fraction(y, 1))
    id = len(answer)
    answer.append([1, x, y])
    list[Point(Fraction(x, 1), Fraction(y, 1))] = id
    ref.append(Point(Fraction(x, 1), Fraction(y, 1)))
    return Point(Fraction(x, 1), Fraction(y, 1))


def draw_op2(s, t, u, v):
    if Line(ref[s], ref[t]) ^ Line(ref[u], ref[v]) in list:
        return Line(ref[s], ref[t]) ^ Line(ref[u], ref[v])
    id = len(answer)
    answer.append([2, s + 1, t + 1, u + 1, v + 1])
    list[Line(ref[s], ref[t]) ^ Line(ref[u], ref[v])] = id
    ref.append(Line(ref[s], ref[t]) ^ Line(ref[u], ref[v]))
    return ref[-1]


def parrallel_y_grid_binary_line(x, bound, L, R):
    l = Fraction(L, 1)
    r = Fraction(R, 1)
    ul = draw_op1(L, 2)
    ur = draw_op1(R, 2)
    dl = draw_op1(L, 0)
    dr = draw_op1(R, 0)
    ml = draw_op1(L, 1)
    mr = draw_op1(R, 1)
    for i in range(bound):
        mid = (l + r) * Fraction(1, 2)

        sm = draw_op2(list[ul], list[mr], list[ur], list[ml])
        tm = draw_op2(list[dl], list[mr], list[dr], list[ml])
        um = draw_op2(list[ul], list[ur], list[sm], list[tm])
        dm = draw_op2(list[dl], list[dr], list[sm], list[tm])
        mm = draw_op2(list[ml], list[mr], list[sm], list[tm])
        if mid == Fraction(L, 1) + Fraction(x, 1 << bound):
            return (um, dm)
        elif mid < Fraction(L, 1) + Fraction(x, 1 << bound):
            l = mid
            ul = um
            dl = dm
            ml = mm
        else:
            r = mid
            ur = um
            dr = dm
            mr = mm
    return (Point(), Point())


def parrallel_x_grid_binary_line(y, bound, L, R):
    l = Fraction(L, 1)
    r = Fraction(R, 1)
    ul = Point(Fraction(2, 1), Fraction(L, 1))
    ur = Point(Fraction(2, 1), Fraction(R, 1))
    dl = Point(Fraction(0, 1), Fraction(L, 1))
    dr = Point(Fraction(0, 1), Fraction(R, 1))
    ml = Point(Fraction(1, 1), Fraction(L, 1))
    mr = Point(Fraction(1, 1), Fraction(R, 1))
    draw_op1(2, L)
    draw_op1(2, R)
    draw_op1(0, L)
    draw_op1(0, R)
    draw_op1(1, L)
    draw_op1(1, R)
    for i in range(bound):
        mid = (l + r) * Fraction(1, 2)
        sm = draw_op2(list[ul], list[mr], list[ur], list[ml])
        tm = draw_op2(list[dl], list[mr], list[dr], list[ml])
        um = draw_op2(list[ul], list[ur], list[sm], list[tm])
        dm = draw_op2(list[dl], list[dr], list[sm], list[tm])
        mm = draw_op2(list[ml], list[mr], list[sm], list[tm])
        if mid == Fraction(L, 1) + Fraction(y, 1 << bound):
            return (um, dm)
        elif mid < Fraction(L, 1) + Fraction(y, 1 << bound):
            l = mid
            ul = um
            dl = dm
            ml = mm
        else:
            r = mid
            ur = um
            dr = dm
            mr = mm
    return (Point(), Point())


def bound(x):
    for i in range(31, -1, -1):
        if (x >> i) & 1:
            return i + 1
    return 0


def shift_parrallel_x_line(ul, um, ur, cur):
    dl = draw_op1(0, 0)
    dm = draw_op1(1, 0)
    dr = draw_op1(2, 0)
    Ul = draw_op1(0, 2)
    Um = draw_op1(1, 2)
    Ur = draw_op1(2, 2)
    sl = dl
    sm = dm
    sr = dr
    smdl, smul = parrallel_y_grid_binary_line(1, 1, 0, 1)
    smdr, smur = parrallel_y_grid_binary_line(1, 1, 1, 2)
    b = bound(cur)
    for i in range(b - 2, -1, -1):
        tmpl = draw_op2(list[smdl], list[smul], list[ul], list[ur])
        stmpl = draw_op2(list[smdl], list[smul], list[sl], list[sr])
        tmpr = draw_op2(list[smdr], list[smur], list[ul], list[ur])
        stmpr = draw_op2(list[smdr], list[smur], list[sl], list[sr])
        new_ul = draw_op2(list[dm], list[tmpl], list[dl], list[Ul])
        new_ur = draw_op2(list[dm], list[tmpr], list[dr], list[Ur])
        new_um = draw_op2(list[dm], list[Um], list[new_ul], list[new_ur])
        new_sl = draw_op2(list[dm], list[stmpl], list[dl], list[Ul])
        new_sr = draw_op2(list[dm], list[stmpr], list[dr], list[Ur])
        new_sm = draw_op2(list[dm], list[Um], list[new_sl], list[new_sr])
        next_l = draw_op2(list[new_sl], list[new_um], list[new_sm], list[new_ul])
        next_r = draw_op2(list[new_sr], list[new_um], list[new_sm], list[new_ur])
        new_sl = draw_op2(list[new_sl], list[new_ul], list[next_l], list[next_r])
        new_sm = draw_op2(list[new_sm], list[new_um], list[next_l], list[next_r])
        new_sr = draw_op2(list[new_sr], list[new_ur], list[next_l], list[next_r])
        ul = new_ul
        um = new_um
        ur = new_ur
        sl = new_sl
        sm = new_sm
        sr = new_sr
        if (cur >> i) & 1:
            new_ul = draw_op2(list[ul], list[sl], list[um], list[sr])
            new_ur = draw_op2(list[ur], list[sr], list[um], list[sl])
            new_um = draw_op2(list[um], list[sm], list[new_ul], list[new_ur])
            sl = ul
            sm = um
            sr = ur
            ul = new_ul
            um = new_um
            ur = new_ur
    return (ul, ur)


def shift_parrallel_y_line(ul, um, ur, cur):
    dl = draw_op1(0, 0)
    dm = draw_op1(0, 1)
    dr = draw_op1(0, 2)
    Ul = draw_op1(2, 0)
    Um = draw_op1(2, 1)
    Ur = draw_op1(2, 2)
    sl = dl
    sm = dm
    sr = dr
    smdl, smul = parrallel_x_grid_binary_line(1, 1, 0, 1)
    smdr, smur = parrallel_x_grid_binary_line(1, 1, 1, 2)
    b = bound(cur)
    for i in range(b - 2, -1, -1):
        tmpl = draw_op2(list[smdl], list[smul], list[ul], list[ur])
        stmpl = draw_op2(list[smdl], list[smul], list[sl], list[sr])
        tmpr = draw_op2(list[smdr], list[smur], list[ul], list[ur])
        stmpr = draw_op2(list[smdr], list[smur], list[sl], list[sr])
        new_ul = draw_op2(list[dm], list[tmpl], list[dl], list[Ul])
        new_ur = draw_op2(list[dm], list[tmpr], list[dr], list[Ur])
        new_um = draw_op2(list[dm], list[Um], list[new_ul], list[new_ur])
        new_sl = draw_op2(list[dm], list[stmpl], list[dl], list[Ul])
        new_sr = draw_op2(list[dm], list[stmpr], list[dr], list[Ur])
        new_sm = draw_op2(list[dm], list[Um], list[new_sl], list[new_sr])
        next_l = draw_op2(list[new_sl], list[new_um], list[new_sm], list[new_ul])
        next_r = draw_op2(list[new_sr], list[new_um], list[new_sm], list[new_ur])
        new_sl = draw_op2(list[new_sl], list[new_ul], list[next_l], list[next_r])
        new_sm = draw_op2(list[new_sm], list[new_um], list[next_l], list[next_r])
        new_sr = draw_op2(list[new_sr], list[new_ur], list[next_l], list[next_r])
        ul = new_ul
        um = new_um
        ur = new_ur
        sl = new_sl
        sm = new_sm
        sr = new_sr
        if (cur >> i) & 1:
            new_ul = draw_op2(list[ul], list[sl], list[um], list[sr])
            new_ur = draw_op2(list[ur], list[sr], list[um], list[sl])
            new_um = draw_op2(list[um], list[sm], list[new_ul], list[new_ur])
            sl = ul
            sm = um
            sr = ur
            ul = new_ul
            um = new_um
            ur = new_ur
    return (ul, ur)


def work_y_grid(a, b):
    A, B = parrallel_y_grid_binary_line(b, bound(b), 0, 1)
    C, D = parrallel_y_grid_binary_line(b, bound(b), 1, 2)
    E, F = parrallel_x_grid_binary_line(1, bound(b), 0, 1)
    G = draw_op2(list[A], list[B], list[E], list[F])
    H = draw_op2(list[C], list[D], list[E], list[F])
    O = draw_op1(0, 0)
    Q = draw_op1(0, 2)
    I = draw_op1(1, 2)
    J = draw_op1(1, 0)
    K = draw_op2(list[G], list[O], list[I], list[J])
    L = draw_op1(2, 2)
    M = draw_op1(2, 0)
    N = draw_op2(list[H], list[J], list[L], list[M])
    P = draw_op2(list[K], list[N], list[O], list[Q])
    S, T = shift_parrallel_x_line(P, K, N, a)
    return (S, T)


A, B = work_y_grid(c, d)


def work_x_grid(a, b):
    A, B = parrallel_x_grid_binary_line(b, bound(b), 0, 1)
    C, D = parrallel_x_grid_binary_line(b, bound(b), 1, 2)
    E, F = parrallel_y_grid_binary_line(1, bound(b), 0, 1)
    G = draw_op2(list[A], list[B], list[E], list[F])
    H = draw_op2(list[C], list[D], list[E], list[F])
    Q = draw_op1(2, 0)
    O = draw_op1(0, 0)
    I = draw_op1(2, 1)
    J = draw_op1(0, 1)
    K = draw_op2(list[G], list[O], list[I], list[J])
    L = draw_op1(2, 2)
    M = draw_op1(0, 2)
    N = draw_op2(list[H], list[J], list[L], list[M])
    P = draw_op2(list[K], list[N], list[O], list[Q])
    S, T = shift_parrallel_y_line(P, K, N, a)
    return (S, T)


C, D = work_x_grid(a, b)

draw_op2(list[A], list[B], list[C], list[D])

print(len(answer))
for i in answer:
    for j in range(len(i)):
        end = "\n" if j + 1 == len(i) else " "
        print(i[j], end=end)
