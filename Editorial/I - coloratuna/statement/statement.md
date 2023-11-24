# 花腔星云

## 题目背景

$\textrm{And up there in the heavens}$
高高在上 于天堂之中

$\textrm{Galileo and those pining for the moon}$
伽利略和前人们伫立于此

$\textrm{Know it's a slow burn}$
深知过程必然缓慢

$\textrm{Through Pioneer and Helix}$
掠过先驱者号与螺旋星云

$\textrm{Oumuamua, Heliopause, and Neptune}$
奥陌陌，日球层顶与海王星

$\textrm{We're a slow-burning tune}$
韵律缓慢燃烧

$\textrm{But we'll get there}$
故事延绵亘久

—— $\textit{Coloratura}$ 花腔星云，$\textrm{Coldplay}$

## 题目描述

可爱的序列扑满看到了一片美丽的花腔星云。

这片星云有 $n$ 颗行星，第 $i$ 颗行星的种类为 $a_i$。

在这个宇宙中，一共有 $3$ 种行星，编号为 $1, 2, 3$。

接下来，序列扑满用 $q$ 种方式欣赏并记录这片星云。

第 $i$ 种欣赏方式用一个三元组 $\lparen l_i, r_i, v_i \rparen$ 表示，代表第 $l_i$ 颗至第 $r_i$ 颗行星的种类编号的乘积，对 $4$ 取模的值为 $v_i$。

现在可爱的序列扑满将行星的个数 $n$，欣赏方式数量 $q$ 和每种欣赏方式的三元组 $\lparen l_i, r_i, v_i \rparen$ 告诉了你，你能不能猜出花腔星云中的每颗行星的种类呢？

由于序列扑满很可爱，所以如果给定的信息产生了矛盾，你也要告诉序列扑满它的记录出错了。

## 输入格式

第一行两个整数 $n, q$，含义见题目描述。

接下来 $q$ 行，每行三个整数 $l_i, r_i, v_i$，代表给定的三元组。

## 输出格式

第一行一个字符串 `YES` 或 `NO`，若有解则输出 `YES`，反之输出 `NO`。

若有解，请输出 $n$ 个正整数，代表一个满足条件的序列 $a_j$。

字符串大小写不敏感，即 `yEs`、`Yes`、`yes` 等均会判定为 `YES`。

如果有解，你可以输出**任意**满足条件的序列。

## 样例 #1

### 样例输入 #1

```
2 2
1 2 1
1 2 2
```

### 样例输出 #1

```
NO
```

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
YES
2 3 3 1 3 1 3 3 3 1 1
```

## 提示

对于 $100\%$ 的数据，$1 \le n \le 8 \cdot {10}^3$，$0 \le q \le 8 \cdot {10}^3$，$0 \le v_i < 4$。

|      子任务编号      |                    限制                     | 分数  |
| :------------------: | :-----------------------------------------: | :---: |
| $\textrm{Subtask 1}$ |                   $q = 0$                   | 2 pt  |
| $\textrm{Subtask 2}$ |             $1 \le n, q \le 10$             | 13 pt |
| $\textrm{Subtask 3}$ |      $1 \le n, q \le 10^2$，$v_i = 2$       | 17 pt |
| $\textrm{Subtask 4}$ | $1 \le n, q \le {10}^3$，$v_i \in \{1, 3\}$ | 27 pt |
| $\textrm{Subtask 5}$ |       $1 \le n, q \le 8 \cdot {10}^3$       | 41 pt |