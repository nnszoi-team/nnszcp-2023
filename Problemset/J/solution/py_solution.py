from fractions import Fraction

class Point:

    def __init__(self, x : Fraction = Fraction(), y : Fraction = Fraction()):
        self.x = x
        self.y = y
    
    def __eq__(self, other) -> bool:
        return self.x == other.x and self.y == other.y
    
    def __hash__(self) -> int:
        return int(self.x * int(1e50) + self.y)

class Line:

    def __init__(self, A : Point, B : Point):
        self.a = A.y - B.y
        self.b = B.x - A.x
        self.c = B.y * A.x - B.x * A.y
    
    def __xor__(self, other) -> Point:
        return Point(
            Fraction((self.b * other.c - self.c * other.b) / (self.a * other.b - self.b * other.a)),
            Fraction((self.a * other.c - self.c * other.a) / (self.b * other.a - self.a * other.b))
        )

p, a, b, c, d = [ int(i) for i in input().split() ]

ans = []
ref = []
table = {}

def draw_op1(x : int, y : int) -> Point:
    if (Point(Fraction(x), Fraction(y))) in table:
        return Point(Fraction(x), Fraction(y))
    idx = len(ans)
    ans.append([1, x, y])
    table[Point(Fraction(x), Fraction(y))] = idx
    ref.append(Point(Fraction(x), Fraction(y)))
    return Point(Fraction(x), Fraction(y))

def draw_op2(s : int, t : int, u : int, v : int) -> Point:
    if Line(ref[s], ref[t]) ^ Line(ref[u], ref[v]) in table:
        return Line(ref[s], ref[t]) ^ Line(ref[u], ref[v])
    idx = len(ans)
    ans.append([2, s + 1, t + 1, u + 1, v + 1])
    table[Line(ref[s], ref[t]) ^ Line(ref[u], ref[v])] = idx
    ref.append(Line(ref[s], ref[t]) ^ Line(ref[u], ref[v]))
    return ref[-1]

def parrallel_y_grid_binary_line(x : int, bound : int, L : int, R : int) -> tuple([Point, Point]):
    l = Fraction(L)
    r = Fraction(R)
    ul = draw_op1(L, 2)
    ur = draw_op1(R, 2)
    dl = draw_op1(L, 0)
    dr = draw_op1(R, 0)
    ml = draw_op1(L, 1)
    mr = draw_op1(R, 1)

    for i in range(bound):
        mid = (l + r) * Fraction(1, 2)
        sm = draw_op2(table[ul], table[mr], table[ur], table[ml])
        tm = draw_op2(table[dl], table[mr], table[dr], table[ml])
        um = draw_op2(table[ul], table[ur], table[sm], table[tm])
        dm = draw_op2(table[dl], table[dr], table[sm], table[tm])
        mm = draw_op2(table[ml], table[mr], table[sm], table[tm])
        
        if mid == Fraction(L) + Fraction(x, 1 << bound):
            return (um, dm)
        elif mid < Fraction(L) + Fraction(x, 1 << bound):
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

def parrallel_x_grid_binary_line(y : int, bound : int, L : int, R : int) -> tuple([Point, Point]):
    l = Fraction(L)
    r = Fraction(R)
    ul = Point(Fraction(2), Fraction(L))
    ur = Point(Fraction(2), Fraction(R))
    dl = Point(Fraction(0), Fraction(L))
    dr = Point(Fraction(0), Fraction(R))
    ml = Point(Fraction(1), Fraction(L))
    mr = Point(Fraction(1), Fraction(R))
    draw_op1(2, L)
    draw_op1(2, R)
    draw_op1(0, L)
    draw_op1(0, R)
    draw_op1(1, L)
    draw_op1(1, R)

    for i in range(bound):
        mid = (l + r) * Fraction(1, 2)
        sm = draw_op2(table[ul], table[mr], table[ur], table[ml])
        tm = draw_op2(table[dl], table[mr], table[dr], table[ml])
        um = draw_op2(table[ul], table[ur], table[sm], table[tm])
        dm = draw_op2(table[dl], table[dr], table[sm], table[tm])
        mm = draw_op2(table[ml], table[mr], table[sm], table[tm])
        
        if mid == Fraction(L) + Fraction(y, 1 << bound):
            return (um, dm)
        elif mid < Fraction(L) + Fraction(y, 1 << bound):
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

def highbit(x : int) -> int:
    for i in range(31, -1, -1):
        if (x >> i) & 1:
            return i + 1
    return 0

def shift_parrallel_x_line(ul : Point, um : Point, ur : Point, cur : int) -> tuple([Point, Point]):
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
    b = highbit(cur)
    
    for i in range(b - 2, -1, -1):
        tmpl = draw_op2(table[smdl], table[smul], table[ul], table[ur])
        stmpl = draw_op2(table[smdl], table[smul], table[sl], table[sr])
        tmpr = draw_op2(table[smdr], table[smur], table[ul], table[ur])
        stmpr = draw_op2(table[smdr], table[smur], table[sl], table[sr])
        new_ul = draw_op2(table[dm], table[tmpl], table[dl], table[Ul])
        new_ur = draw_op2(table[dm], table[tmpr], table[dr], table[Ur])
        new_um = draw_op2(table[dm], table[Um], table[new_ul], table[new_ur])
        new_sl = draw_op2(table[dm], table[stmpl], table[dl], table[Ul])
        new_sr = draw_op2(table[dm], table[stmpr], table[dr], table[Ur])
        new_sm = draw_op2(table[dm], table[Um], table[new_sl], table[new_sr])
        next_l = draw_op2(table[new_sl], table[new_um], table[new_sm], table[new_ul])
        next_r = draw_op2(table[new_sr], table[new_um], table[new_sm], table[new_ur])
        new_sl = draw_op2(table[new_sl], table[new_ul], table[next_l], table[next_r])
        new_sm = draw_op2(table[new_sm], table[new_um], table[next_l], table[next_r])
        new_sr = draw_op2(table[new_sr], table[new_ur], table[next_l], table[next_r])
        ul = new_ul
        um = new_um
        ur = new_ur
        sl = new_sl
        sm = new_sm
        sr = new_sr
        if (cur >> i) & 1:
            new_ul = draw_op2(table[ul], table[sl], table[um], table[sr])
            new_ur = draw_op2(table[ur], table[sr], table[um], table[sl])
            new_um = draw_op2(table[um], table[sm], table[new_ul], table[new_ur])
            sl = ul
            sm = um
            sr = ur
            ul = new_ul
            um = new_um
            ur = new_ur
    
    return (ul, ur)

def shift_parrallel_y_line(ul : Point, um : Point, ur : Point, cur : int) -> tuple([Point, Point]):
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
    b = highbit(cur)

    for i in range(b - 2, -1, -1):
        tmpl = draw_op2(table[smdl], table[smul], table[ul], table[ur])
        stmpl = draw_op2(table[smdl], table[smul], table[sl], table[sr])
        tmpr = draw_op2(table[smdr], table[smur], table[ul], table[ur])
        stmpr = draw_op2(table[smdr], table[smur], table[sl], table[sr])
        new_ul = draw_op2(table[dm], table[tmpl], table[dl], table[Ul])
        new_ur = draw_op2(table[dm], table[tmpr], table[dr], table[Ur])
        new_um = draw_op2(table[dm], table[Um], table[new_ul], table[new_ur])
        new_sl = draw_op2(table[dm], table[stmpl], table[dl], table[Ul])
        new_sr = draw_op2(table[dm], table[stmpr], table[dr], table[Ur])
        new_sm = draw_op2(table[dm], table[Um], table[new_sl], table[new_sr])
        next_l = draw_op2(table[new_sl], table[new_um], table[new_sm], table[new_ul])
        next_r = draw_op2(table[new_sr], table[new_um], table[new_sm], table[new_ur])
        new_sl = draw_op2(table[new_sl], table[new_ul], table[next_l], table[next_r])
        new_sm = draw_op2(table[new_sm], table[new_um], table[next_l], table[next_r])
        new_sr = draw_op2(table[new_sr], table[new_ur], table[next_l], table[next_r])
        ul = new_ul
        um = new_um
        ur = new_ur
        sl = new_sl
        sm = new_sm
        sr = new_sr
        if (cur >> i) & 1:
            new_ul = draw_op2(table[ul], table[sl], table[um], table[sr])
            new_ur = draw_op2(table[ur], table[sr], table[um], table[sl])
            new_um = draw_op2(table[um], table[sm], table[new_ul], table[new_ur])
            sl = ul
            sm = um
            sr = ur
            ul = new_ul
            um = new_um
            ur = new_ur
    
    return (ul, ur)

def work_y_grid(a : int, b : int) -> tuple([Point, Point]):
    A, B = parrallel_y_grid_binary_line(b, highbit(b), 0, 1)
    C, D = parrallel_y_grid_binary_line(b, highbit(b), 1, 2)
    E, F = parrallel_x_grid_binary_line(1, highbit(b), 0, 1)
    G = draw_op2(table[A], table[B], table[E], table[F])
    H = draw_op2(table[C], table[D], table[E], table[F])
    O = draw_op1(0, 0)
    Q = draw_op1(0, 2)
    I = draw_op1(1, 2)
    J = draw_op1(1, 0)
    K = draw_op2(table[G], table[O], table[I], table[J])
    L = draw_op1(2, 2)
    M = draw_op1(2, 0)
    N = draw_op2(table[H], table[J], table[L], table[M])
    P = draw_op2(table[K], table[N], table[O], table[Q])
    S, T = shift_parrallel_x_line(P, K, N, a)
    return (S, T)

A, B = work_y_grid(c, d)

def work_x_grid(a : int, b : int) -> tuple([Point, Point]):
    A, B = parrallel_x_grid_binary_line(b, highbit(b), 0, 1)
    C, D = parrallel_x_grid_binary_line(b, highbit(b), 1, 2)
    E, F = parrallel_y_grid_binary_line(1, highbit(b), 0, 1)
    G = draw_op2(table[A], table[B], table[E], table[F])
    H = draw_op2(table[C], table[D], table[E], table[F])
    Q = draw_op1(2, 0)
    O = draw_op1(0, 0)
    I = draw_op1(2, 1)
    J = draw_op1(0, 1)
    K = draw_op2(table[G], table[O], table[I], table[J])
    L = draw_op1(2, 2)
    M = draw_op1(0, 2)
    N = draw_op2(table[H], table[J], table[L], table[M])
    P = draw_op2(table[K], table[N], table[O], table[Q])
    S, T = shift_parrallel_y_line(P, K, N, a)
    return (S, T)

C, D = work_x_grid(a, b)

draw_op2(table[A], table[B], table[C], table[D])

print(len(ans))
for i in ans:
    for v in i:
        print(v, end = " ")
    print()