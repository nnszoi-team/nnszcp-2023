## 题意

用不超过 $1500$ 次操作作出点 $(\frac{a}{b}, \frac{c}{d})$。
操作包括：
* 作出一个整点；
* 作出两条经过已知点的直线的交点。

每次作出的点都要在 $(0, 0)$ 和 $(p, p)$ 之间，即 $0 \le x, y \le p$。
保证 $1 \le a \le b \le 10^7$，$1 \le c \le d \le 10^7$，$2 \le p \le 10^7$。

下文记 $t = \max(b, d)$。

## Subtask 0

**限制：$t \le 10^3$，$p \ge 10^7$。**

这时怎么连都是合法的。
连接 $(0, 0)$ 和 $(1, d)$。取 $x=c$ 与其交于 $(c,\frac{c}{d})$。
这样就可以作出 $y = \frac{c}{d}$。
同理作出 $x = \frac{a}{b}$。交点就是 $\left(\frac{a}{b}, \frac{c}{d}\right)$。

## Subtask 1

**限制：$t \le 10^6$，$p \ge t$。**

和上一个没有什么区别。只是为了防止写挂留了一档分。

## Subtask 2

**限制：$t \le 10^7$，$p \ge \lceil \frac{t}{2} \rceil + 1$。**

这时你不能直接连接 $(0, 0)$ 和 $(1, t)$ 了。
你可以先作出 $\left( \frac{1}{2}, \frac{t}{2} \right)$ 或 $\left( 1, \frac{t}{2} \right)$。然后再进行连接。
假设 $t$ 对应的分子为 $s$。如果 $s \ge \frac{t}{2}$ 就作第二个点，反之作第一个点。

## Subtask 3

**限制：$t \le 10^7$，$p \ge \lceil \sqrt{t} \rceil + 2$。**

发现这是根号，根号分治一下。
将每一个格子分成 $\lceil \sqrt{t} \rceil \times \lceil \sqrt{t} \rceil$ 后，情况转化为了 Subtask 1。
然后就能做了。

## Subtask 3

**限制：$t \le 10^7$，$p \ge 2$。**

我们先作出 $\frac{1}{t}$，然后将其扩大 $s$ 倍。
可以作出 $\left( \frac{t}{2^k}, \frac{1}{2^k} \right)$，其中 $2^k>t$。这样就有了 $\frac{1}{t}$。
扩大 $s$ 倍可以考虑倍增。
实现的细节很多。注意封装。

