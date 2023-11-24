## 题目背景

And up there in the heavens 高高在上 于天堂之中

Galileo and those pining for the moon 伽利略和前人们伫立于此

Know it's a slow burn 深知过程必然缓慢

Through Pioneer and Helix 掠过先驱者号与螺旋星云

Oumuamua, Heliopause, and Neptune 奥陌陌，日球层顶与海王星

We're a slow-burning tune 韵律缓慢燃烧

But we'll get there 故事延绵亘久

—— Coloratura 花腔星云，Coldplay

## 题目描述

可爱的序列扑满看到了一片美丽的花腔星云。

在这个宇宙一共有 $3$ 种行星，编号为 $1, 2, 3$，而这片星云有 $n$ 颗行星，第 $i$ 颗行星的种类为 $a_i$。

接下来，序列扑满用 $q$ 种方式欣赏这片星云。第 $i$ 种欣赏方式用一个三元组 $\left(l_i, r_i, v_i\right)$ 表示，代表第 $l_i$ 颗至第 $r_i$ 颗行星的种类编号的乘积，除以 $4$ 的余数为 $v_i$。

现在可爱的序列扑满将行星的个数 $n$，欣赏方式数量 $q$ 和每种欣赏方式的三元组 $\left(l_i, r_i, v_i\right)$ 告诉了你，你能不能猜出花腔星云中的每颗行星可能的种类呢？

由于序列扑满很可爱，所以记录一定没有出错，也就是说存在一种行星种类的情况，满足序列扑满的所有欣赏方式。

## 输入格式

从标准输入读入数据。

第一行两个整数 $n, q$，含义见题目描述。

接下来 $q$ 行，每行三个整数 $l_i, r_i, v_i$，代表给定的三元组。

## 输出格式

输出到标准输出中。

输出 $n$ 个正整数，代表一个满足条件的序列 $a_j$。

**本题使用 Special Judge**。你可以输出**任意**满足条件的序列。

## 样例 #1

### 样例输入 #1

```
6 3
1 3 3
2 4 2
5 6 1
```

### 样例输出 #1

```
3 1 1 2 3 3
```

### 样例解释 #1

第一种欣赏方式 $\left(1, 3, 3\right)$ 即 $\left(3 \times 1 \times 1\right) \bmod 4 = 3$。

第二个欣赏方式 $\left(2, 4, 2\right)$ 即 $\left(1 \times 1 \times 2\right) \bmod 4 = 2$。

第三个欣赏方式 $\left(5, 6, 1\right)$ 即 $\left(3 \times 3\right) \bmod 4 = 1$。

据此，所有的欣赏方式都得到了满足，3, 1, 1, 2, 3, 3 是一组合法的情况。

## 样例 #2

### 样例输入 #2

```
11 4
3 10 3
1 2 2
2 3 1
7 8 1
```

### 样例输出 #2

```
2 3 3 1 3 1 3 3 3 1 1
```

## 样例 #3

### 样例输入 #3

```
9 41 3 23 6 25 9 23 6 2
```

### 样例输出 #3

```
2 1 3 2 1 3 2 1 3
```

## 提示

对于 $100\%$ 的数据，$1 \le n \le 2 \times {10}^4$，$0 \le q \le 2 \times {10}^4$，$0 \le v_i < 4$。

| 子任务编号 |  限制 | 分数 |
|:---:|:---:|:---:|
| $\textrm{Subtask 0}$ | $q = 0$ | $2$ |
| $\textrm{Subtask 1}$ | $1 \le n, q \le 10$ | $13$ |
| $\textrm{Subtask 2}$ | $1 \le n, q \le 10^2$，$v_i = 2$ | $17$ |
| $\textrm{Subtask 3}$ | $1 \le n, q \le {10}^3$，$v_i \in \{1, 3\}$ | $27$ |
| $\textrm{Subtask 4}$ | $1 \le n, q \le 2 \times {10}^4$ | $41$ |



