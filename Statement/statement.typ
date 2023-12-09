#set text(
  font: ("New Computer Modern", "Noto Serif CJK SC"),
  size: 12pt
)

#show heading.where(level: 1): it => text(
  font: ("New Computer Modern", "Noto Sans CJK SC"), 
  size: 20pt,
  weight: "bold",
  it.body
)

#show heading.where(level: 2): it => text(
  font: ("New Computer Modern", "Noto Sans CJK SC"), 
  size: 16pt,
  weight: "semibold",
  it.body + [
    
  ]
)

#show heading.where(level: 3): it => text(
  font: ("New Computer Modern", "Noto Sans CJK SC"), 
  size: 14pt,
  weight: "medium",
  it.body + [
    
  ]
)

#show raw.where(block: true): block.with(
  fill: luma(240),
  inset: 10pt,
  radius: 4pt,
)

#show raw.where(block: false): box.with(
  fill: luma(240),
  inset: (x: 3pt, y: 0pt),
  outset: (y: 3pt),
  radius: 2pt,
)

#show raw: set text(font: "Fira Code", size: 12pt)

#set raw(block: true)

#set par(
 justify: true,
 leading: 0.6em
)

#show strong: set text(font: ("New Computer Modern", "Noto Sans CJK SC"), weight: "extralight")

#image("head2.svg")

#align(center, text(18pt)[
  *南宁三中青山校区第 13 届科技文化节程序设计竞赛*
])

#align(center, text(font: "New Computer Modern", size: 28pt)[
  NNSZCP-2023
])

#align(center, text(16pt)[
  比赛时间：2023 年 12 月 10 日 8:30 \~ 11:30
])

\

#align(center, [
  #image("nnsz_icon.jpg", width: 33%)
])

\

#align(center, [
  #table(
  columns: (6em, 10em, 6em, 6em, 6em),
  inset: 6pt,
  align: auto,
  [*题目编号*], [*题目名称*], [*时间限制*], [*空间限制*], [*子任务数量*],
  [*A*], [欢迎光临], [1.0 s], [128 MiB], [3], 
  [*B*], [反应原理], [2.0 s], [256 MiB], [3], 
  [*C*], [暮光闪闪], [2.0 s], [256 MiB], [3], 
  [*D*], [初生几何], [2.0 s], [128 MiB], [2], 
  [*E*], [填数游戏], [1.0 s], [128 MiB], [4], 
  [*F*], [中考录取], [1.0 s], [128 MiB], [2],
  [*G*], [排序算法], [2.0 s], [256 MiB], [3], 
  [*H*], [购买车券], [2.0 s], [256 MiB], [5], 
  [*I*], [花卉培育], [2.0 s], [256 MiB], [5], 
  [*J*], [繁星满天], [2.0 s], [256 MiB], [5], 
)
])

#pagebreak()

#set page(
  margin: (x: 2cm, y: 2cm), 
  header: [
    #set align(right)
    #set text(font: "Fira Code", size: 10pt)
    NNSZCP-2023\
    2023/12/10
  ],
  numbering: "1 / 1",
  number-align: center + bottom,
)

= Problem A. 欢迎光临 <problem-a.-欢迎光临>

南宁市第三中学是广西首批重点中学、广西首批示范性高中、首批普通高中新课程新教材实施国家级示范校。学校前身为 1897 年维新人士余镜清创办的南宁乌龙寺讲堂。学校目前拥有青山校区、五象校区、初中部青秀校区、初中部五象校区、初中部江南校区等 5 个校区，形成多校区集团办学模式。历经 126 年办学历史的洗礼与积淀，南宁三中以「真 · 爱教育」的办学思想和「德育为先，文理并重，崇尚一流」的办学特色饮誉华夏大地，成为莘莘学子向往的求知殿堂。

为了欢迎各位新老选手的到来，南宁三中 01 社的成员们写了一句欢迎语。但是你作为一名新选手，不是很了解夹杂在欢迎语中的各种梗，你只知道 `nnsz` 是「南宁三中」的意思。

聪明的你想知道，在欢迎语中，是否存在一段连续部分（即子串）为 `nnsz`。

== 输入格式 <输入格式>
给定一个仅包含小写英文字母且不包含空格的字符串 $S$，代表欢迎语。

== 输出格式 <输出格式>
如果欢迎语 $S$ 存在一段连续部分（即子串）为 `nnsz`，输出 `YES`，否则输出 `NO`。

#strong[答案不区分大小写]。例如，当答案为 `YES` 时，`yes`，`yEs`，`YEs` 等答案均可被判定为正确答案。

== 样例 1 <样例-1>
=== 样例 1 输入 <样例-1-输入>
```
welcometonnsz
```

=== 样例 1 输出 <样例-2-输出>
```
YES
```

== 样例 2 <样例-2>
=== 样例 2 输入 <样例-2-输入>
```
nanningsanzhong
```

=== 样例 2 输出 <样例-2-输出-1>
```
NO
```

#pagebreak()

== 样例 3 <样例-3>
=== 样例 3 输入 <样例-3-输入>
```
nocommander
```

=== 样例 3 输出 <样例-3-输出>
```
NO
```

== 数据范围 <数据范围>
记 $n$ 为 $S$ 的长度。

对于 100% 的数据，保证：

- $1 lt.eq n lt.eq 100$；
- $S$ 中仅包含小写英文字母。

== 子任务 <子任务>
#block[
  #set enum(numbering: "1.", start: 0)
  + （45 分）$n lt.eq 3$；
  + （5 分）$n = 4$；
  + （50 分）无额外限制。
]

#pagebreak()

= Problem B. 反应原理 <problem-b.-反应原理>

你说的对，但是《化学》是由化学家自主研发的一款全新开放世界冒险游戏。故事发生在一个被称作「微观状态」的架空世界，在这里，被选中的原子将被授予「电子」，导引键能之力。

你将扮演一位名为「臭写题的」的神秘角色，在自由的刷题中邂逅性质各异、能力独特的化合物们，和他们一起击败强题，找回失散的离子——同时，逐步发掘「元素周期表」的真相。

小 P 和小 Q 是同桌。这天，化学老师在课上让他们回答活化能的定义。

化学老师说：「一个化学反应由多个反应步骤依次进行完成。已知某反应共有 $n$ 个反应步骤，初始时物质的总能量为 $a_0$，定义第 $i$ 个反应步骤后，物质的总能量为 $a_i$。」

小 P 说：「化学反应的活化能是整个化学反应进程中的能量的#strong[最大值]，即 $max_(i eq 0)^n brace.l a_i brace.r$。」

小 Q 说：「化学反应的活化能是某个反应步骤进行前后，总能量#strong[变化量]的#strong[最大值]。即 $max_(i eq 0)^(n minus 1) brace.l a_(i plus 1) minus a_i brace.r$。」

显然两人的回答都不正确。但化学老师还是给了你一个化学反应，并请你分别求出在两人眼里，这个反应的活化能是多少？

#strong[注意本题中物质的能量可能为负值]。

== 输入格式 <输入格式-1>
第一行一个正整数 $n$，含义见题目描述。

接下来一行 $n plus 1$ 个整数，第 $i$ 个整数代表 $a_(i minus 1)$。

== 输出格式 <输出格式-1>
第一行包含一个整数，表示在小 P 眼里，这个反应的活化能。

第二行包含一个整数，表示在小 Q 眼里，这个反应的活化能。

== 样例 1 <样例-1-1>
=== 样例 1 输入 <样例-1-输入-1>
```
4
1 4 6 10 12
```

=== 样例 1 输出 <样例-1-输出>
```
12
4
```

#pagebreak()

== 样例 2 <样例-2-1>
=== 样例 2 输入 <样例-2-输入-1>
```
4
31 12 23 13 -21
```

=== 样例 2 输出 <样例-2-输出-2>
```
31
11
```

== 提示 <提示>
==== 样例 1 解释 <样例-1-解释>
在小 P 眼里，这个反应的活化能为 $max brace.l 1 comma 4 comma 6 comma 10 comma 12 brace.r eq 12$。

在小 Q 眼里，这个反应的活化能为 $max brace.l 4 minus 1 comma 6 minus 4 comma 10 minus 6 comma 12 minus 10 brace.r eq 4$。

== 数据范围 <数据范围-1>
对 100% 的数据，保证：

- $1 lt.eq n lt.eq 3 times 10^5$；
- $minus 10^7 lt.eq a_i lt.eq 10^7$；
- 所有输入数据都是整数。

== 子任务 <子任务-1>
#block[
  #set enum(numbering: "1.", start: 0)
  + （25 分）$2 lt.eq n lt.eq 10^3$；
  + （25 分）对 $0 lt.eq i lt n$，$a_i lt.eq a_(i plus 1)$；
  + （50 分）无额外限制。
]

#pagebreak()

= Problem C. 暮光闪闪 <problem-c.-暮光闪闪>

#figure(
  image("twilight.jpg", width: 33%)
)

小马利亚要建造一批新的建筑，公主暮光闪闪一共计划了 $n$ 栋建筑物，每一栋建筑物的高度为 $h_i$。现在，作为该工程的领导者，云宝希望城市的规划能够为天马们提供一些便利。

这些建筑将有 $m$ 匹天马入住。对于第 $i$ 匹天马，其飞行的高度为 $s_i$。

天马们彼此都很熟识，它们经常相互串门，在建筑之间穿梭。云宝认为：如果一对#strong[不同]的建筑物高度差的绝对值不大于这匹天马的飞行高度，那么这匹天马就能在这对建筑之间穿梭。具体地，若对于第 $i$ 匹天马和一对不同的建筑物 $lr((u comma v))$（$u eq.not v$），这匹天马能在这对建筑物之间穿梭，当且仅当 $lr(| h_u minus h_v |) lt.eq s_i$。

云宝想知道：每一匹天马最多能够在多少对#strong[不同]的建筑之间穿梭？由于工期紧张，她需要你的帮助，因此请你帮忙解决这个问题。

这里的一对建筑物 $lr((u comma v))$ 是#strong[无序的]，也就是说认为 $lr((u comma v))$ 和 $lr((v comma u))$ 是完全等价的。

== 输入格式 <输入格式-2>
第一行两个正整数 $n, m$。

第二行 $n$ 个正整数，代表 $h_1, h_2, h_3, dots, h_n$。

第三行 $m$ 个正整数，代表 $s_1, s_2, s_3, dots, s_m$。

== 输出格式 <输出格式-2>
一共 $m$ 行，每行一个整数，代表答案。

== 样例 1 <样例-1-2>
=== 样例 1 输入 <样例-1-输入-2>
```
3 2
1 2 3
1 2
```

#pagebreak()

=== 样例 1 输出 <样例-1-输出-1>
```
2
3
```

== 提示 <提示-1>
==== 样例 1 解释 <样例-1-解释-1>
对于 $s_1 = 1$ 的天马，它最多可以在建筑 $1$ 与建筑 $2$、建筑 $2$ 与建筑 $3$ 之间穿梭。

对于 $s_2 = 2 $ 的天马，它最多可以在建筑 $1$ 与建筑 $2$、建筑 $1$ 与建筑 $3$、建筑 $2$ 与建筑 $3$ 之间穿梭。

== 数据范围 <数据范围-2>
对于 100% 的数据，保证：

- $1 <= m <= 10^5$；
- $1 <= n <= 2 times 10^3$；
- $1 lt.eq h_i comma s_i lt.eq 10^9$；
- 所有输入数据都是正整数。

== 子任务 <子任务-2>
#block[
  #set enum(numbering: "1.", start: 0)
  + （20 分）$1 lt.eq m lt.eq 100$，$1 lt.eq n lt.eq 100$；
  + （10 分）所有的 $h_i$ 都相等；
  + （70 分）无额外限制。
]

#pagebreak()


= Problem D. 初生几何 <problem-d.-初生几何>

#figure(
  image("mathematics.png", width: 75%) 
)

如图，在平面直角坐标系中，抛物线 $y = x(k - x)$ 与直线 $y = -1$ 相交。抛物线与 $x$ 轴的另一个交点为 $upright(A)$。设#strong[线段] $upright(O A)$ 上存在一动点 $upright(P)$，过点 $upright(P)$ 作 $y$ 轴的平行线交抛物线于点 $upright(B)$，交直线 $y eq minus 1$ 于点 $upright(C)$。试求 $upright(O B)^2 plus upright(A C)^2$ 的最大值。

== 输入格式 <输入格式-5>
每个测试点包含多组测试数据。

每个测试点的第一行包含一个整数 $T$，代表测试数据组数。

接下来的 $T$ 行，每行包含两个正整数 $a, b$，表示 $k = a/b$。

== 输出格式 <输出格式-5>
对于每组测试数据，输出一个#strong[实数]，代表 $upright(O B)^2 plus upright(A C)^2$ 的最大值。

设你的答案为 $x$，标准答案为 $X$，则绝对误差 $Delta x = | X - x |$，相对误差 $E_r = (Delta x) / X$。

当 $Delta x lt.eq 10^(-5)$ 或 $E_r lt.eq 10^(-5)$ 时，你的答案即可被判定为正确答案。

#pagebreak()

== 样例 1 <样例-1-5>
=== 样例 1 输入 <样例-1-输入-5>
```
3
365 254
10000 1
1 10000
```

=== 样例 1 输出 <样例-1-输出-4>
```
3.064991629983
625000050000001.000000000000
1.000000010000
```

== 提示 <提示-4>
=== 样例 1 解释 <样例-1-解释-3>
对于第一组数据，能够证明 $upright(O B)^2 plus upright(A C)^2 lt.eq 197741 / 64516 approx 3.064991629983$。

== 数据范围 <数据范围-5>
对于 100% 的数据，保证：

- $1 lt.eq T lt.eq 10^5$；
- $1 lt.eq a, b lt.eq 10^4$；
- 所有输入数据均为正整数。

== 子任务 <子任务-5>
#block[
  #set enum(numbering: "1.", start: 0)
  + （20 分）$b eq 1$；
  + （80 分）无额外限制。
]

#pagebreak()

= Problem E. 填数游戏 <problem-e.-填数游戏>

#figure(
  image("game.jpg", width: 66%) 
)

二等咒器技官威廉坐在房间的书桌前，天蓝色中夹杂些许红色的长发，面带微笑的妖精少女珂朵莉侍立在旁。烛火轻轻摇曳，若明若暗的光轻轻落在珂朵莉忽明忽暗的脸颊上。珂朵莉明显有一点点紧张，她无处安放的双手有些不安的藏在背后，纠缠在一起，眼神时不时的装作不经意的模样瞟向窗外。

这几天珂朵莉一直闷闷不乐，威廉很担忧，于是他突发奇想。

"让我们来玩一个游戏吧！"

珂朵莉首先说出一个正整数 $k$。

"那就 $68$ 吧，"珂朵莉随即说，"毕竟这里是 $68$ 号岛。"

接着威廉画出了一个 $5 times 5$ 的矩阵。

珂朵莉依次选了一些数（如下图）。每次选出一个数并将其画上圈，再把它所在行和列的其他数划掉，表示这些数都不可以选。不断重复直到所有数都已经被选过或不可以选为止。

经过珂朵莉的验证，发现不管怎么选，最后把画上圈的数加起来，它肯定等于 $68$ 。

#figure(
  image("game_sample.png", width: 90%) 
)

珂朵莉一脸惊讶地问威廉是怎么做到的，可威廉却偏偏卖关子："明天再告诉你。"

好奇心胜的珂朵莉完全等不住，于是找到了聪明的你，希望你能复现这个游戏，并跟她一起研究其中的奥秘。

#strong[珂朵莉把这个游戏形式化地描述给你：]

给定两个正整数 $n comma k$。你需要#strong[构造]一个 $n times n$ 的矩阵 $A$，其中 $A_(i comma j)$ 是#strong[不重复]的整数且 $A_(i comma j) in lr([0 comma k])$，使得其满足：

- 任意选出的不在同行同列的 $n$ 个元素之和为 $k$。

对每组数据，给出一个解或报告无解。

== 输入格式 <输入格式-4>
第一行一个正整数 $T$，表示数据组数。

下面的 $T$ 行，每行两个正整数 $n comma k$。

== 输出格式 <输出格式-4>
输出共 $T$ 组，分别表示每组测试数据的答案。

对于每组测试数据，如果该组测试数据有解，输出 $n$ 行，每行 $n$ 个由空格隔开的整数，第 $i$ 行第 $j$ 个数表示 $A_(i comma j)$，否则仅输出一行一个整数 $minus 1$ 代表无解。

== 样例 1 <样例-1-4>
=== 样例 1 输入 <样例-1-输入-4>
```
1
5 68
```

=== 样例 1 输出 <样例-1-输出-3>
```
7 9 8 6 10
18 20 19 17 21
13 15 14 12 16
1 3 2 0 4
24 26 25 23 27
```

== 样例 2 <样例-2-3>
=== 样例 2 输入 <样例-2-输入-3>
```
1
6 60
```

=== 样例 2 输出 <样例-2-输出-4>
```
-1
```

#pagebreak()

== 提示 <提示-3>
样例 1 的解释见题目描述。

== 数据范围 <数据范围-4>
对于 100% 的数据，保证：

- $1 lt.eq T lt.eq 10$；
- $1 lt.eq n lt.eq 500$；
- $1 lt.eq k lt.eq 10^9$。
- 所有输入数据均为正整数。

== 子任务 <子任务-4>
#block[
  #set enum(numbering: "1.", start: 0)
  + （10 分）$T eq 1$，$n eq 1$；
  + （15 分）$T eq 1$，$1 lt.eq n lt.eq 5$，$1 lt.eq k lt.eq 100$；
  + （25 分）$1 lt.eq n lt.eq 100$，$1 lt.eq k lt.eq 10^5$；
  + （50 分）无额外限制。
]

#pagebreak()

= Problem F. 中考录取 <problem-f.-中考录取>

N 市某年的初中学业考试和高中阶段学校招生考试成绩排名规则如下：

考生需经历语文、数学、英语、物理、化学、道德与法治和历史（以下简称“政史”）共 $6$ 门文化课考试，以及体育考试。

考生在每门考试中都有对应的原始分（为简便起见，我们认为#strong[原始分都是整数]），我们设考生 $i$ 的原始分为

- 语文原始分为 $a_i$；
- 数学原始分为 $b_i$；
- 英语原始分为 $c_i$；
- 物理原始分为 $d_i$；
- 化学原始分为 $e_i$；
- 政史原始分为 $f_i$；
- 体育原始分为 $g_i$；
- 总原始分为 $s_i = a_i + b_i + c_i + d_i + e_i + f_i + g_i$。

对于语文原始分、数学原始分、英语原始分、物理原始分、化学原始分、政史原始分和总原始分共 $7$ 项数据，每项数据都被#strong[从高到低]划分成 A+，A，B+，B，C+，C，D，E 共 $8$ 种等级，但为问题简便起见，我们认为#strong[等级只有 A+  与 A 共 $2$ 种]。

对于每一项数据，教育部门划定了一条分数线 $l$。以语文学科为例，设教育部门为语文学科划定的分数线为 $l_a$，则对于考生 $i$，有：

- 当 $a_i < l_a$ 时，考生 $i$ 的语文等级为 A；
- 当 $a_i gt.eq l_a$ 时，考生 $i$ 的语文等级为 A+；
- 其他科目的对应等级以同样方式评定。

在对每个考生的原始分划分等级后，两名考生的等级组合将按如下规则比较：

- 两名考生中#strong[总分]等级更高的一名的成绩更优；
- 若两名考生的总分等级相同，则两名考生中 A+ 等级的#strong[数量]更多的一名的成绩更优；
- 若两名考生的 A+ 等级的数量仍相同，则#strong[语文]等级更高的一名的成绩更优；
- 若两名考生的语文等级仍相同，则#strong[数学]等级更高的一名的成绩更优；
- 若两名考生的数学等级仍相同，则#strong[英语]等级更高的一名的成绩更优；
- 若两名考生的英语等级仍相同，则#strong[物理]等级更高的一名的成绩更优；
- 若两名考生的物理等级仍相同，则#strong[化学]等级更高的一名的成绩更优；
- 若两名考生的化学等级仍相同，则#strong[政史]等级更高的一名的成绩更优；
- 若两名考生的政史等级仍相同，则直接认为两名考生的成绩#strong[完全相同]，没有优劣之分。（尽管两人的原始分可能不完全相同）

ZSNN 作为 N 市的一所重点高中，是众多优秀学子所向往的学府。自然，想要进入 ZSNN，就要经过激烈的竞争。

该年报考 ZSNN 的考生共有 $n$ 名，而 ZSNN 拟录取的新生人数为 $m$ 人。而教育部门规定，#strong[成绩组合完全相同的人，其报考结果（即录取与否）也应该相同]。这导致了实际录取人数 $m'$ 与拟录取人数 $m$ 可能略有出入。

现在，给出 $n$ 和 $m$，以及 $n$ 名考生的所有原始分数据，和各个科目的分数线。请你求出在保证 $m' gt.eq m$ 的情况下 $m'$ 的#strong[最小值]。

== 输入格式 <输入格式-3>
第一行包含 $7$ 个整数 $l_a, l_b, l_c, l_d, l_e, l_f, l_s$，分别代表语文、数学、英语、物理、化学、政史和总分的分数线。

第二行包含 $2$ 个整数 $n, m$（$m lt.eq n$），分别代表报考 ZSNN 的考生总数和 ZSNN 拟录取的新生人数。

接下来的 $n$ 行中的第 $i$ 行包含 $7$ 个整数 $a_i, b_i, c_i, d_i, e_i, f_i, g_i$，分别代表考生 $i$ 的语文、数学、英语、物理、化学、政史、体育原始分。

== 输出格式 <输出格式-3>
输出一个整数 $m'$，代表实际录取的新生人数。

== 样例 1 <样例-1-3>
=== 样例 1 输入 <样例-1-输入-3>
```
105 106 117 93 97 118 640
2 1
110 113 119 95 98 119 60
105 106 117 93 97 118 36
```

=== 样例 1 输出 <样例-1-输出-2>
```
2
```

== 样例 2 <样例-2-2>
=== 样例 2 输入 <样例-2-输入-2>
```
105 106 117 93 97 118 640
2 1
100 106 115 92 95 114 57
104 105 116 93 96 117 60
```

=== 样例 2 输出 <样例-2-输出-3>
```
1
```

#pagebreak()

== 样例 3 <样例-3-1>
=== 样例 3 输入 <样例-3-输入-1>
```
105 106 117 93 97 118 640
2 1
104 105 116 92 96 117 60
120 120 120 100 100 0 60
```

=== 样例 3 输出 <样例-3-输出-1>
```
1
```

== 样例 4 <样例-4>
=== 样例 4 输入 <样例-4-输入>
```
81 55 33 22 84 5 180
10 3
26 45 51 65 60 1 2
105 69 18 40 24 40 4
54 44 9 85 10 114 11
41 62 69 82 98 52 53
109 78 88 24 91 60 13
103 99 11 73 53 66 0
69 104 63 45 38 92 17
43 119 75 94 6 119 33
76 101 50 12 8 70 51
54 48 21 79 73 27 25
```

=== 样例 4 输出 <样例-4-输出>
```
4
```

#pagebreak()

== 提示 <提示-2>
=== 样例 1 解释 <样例-1-解释-2>
考生 1 与考生 2 的等级组合均为「总分 A+ 和 6A+」，他们应该同时被录取。

=== 样例 2 解释 <样例-2-解释>
考生 1 与考生 2 的等级组合均为「总分 A+ 和 1A+5A」，但在两人语文等级相同的情况下，考生 1 的数学等级高于考生 2 的数学等级。故考生 1 的成绩更优秀，只有考生 1 能被录取。

=== 样例 3 解释 <样例-3-解释>
考生 1 的总分等级为 A+，而考生 2 的总分等级为 A。故考生 1 的成绩更优秀，只有考生 1 能被录取。

== 数据范围 <数据范围-3>
对于 100% 的数据，保证：

- $1 lt.eq m lt.eq n lt.eq 10^5$；
- $0 lt.eq a_i, l_a lt.eq 120$；
- $0 lt.eq b_i, l_b lt.eq 120$；
- $0 lt.eq c_i, l_c lt.eq 100$；
- $0 lt.eq d_i, l_d lt.eq 100$；
- $0 lt.eq e_i, l_e lt.eq 100$；
- $0 lt.eq f_i, l_f lt.eq 100$；
- $0 lt.eq g_i lt.eq 60$；
- $0 lt.eq l_s lt.eq 740$；
- 所有输入数据均为整数。

== 子任务 <子任务-3>
#block[
  #set enum(numbering: "1.", start: 0)
  + （20 分）$1 lt.eq m lt.eq n lt.eq 10$，且所有人的等级组合均不相同；
  + （80 分）无额外限制。
]

#pagebreak()

= Problem G. 排序算法 <problem-g.-排序算法>

某日，小 C 翻出了不知多久以前写的老代码，内容如下：

```cpp
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] < a[j]) {
                std::swap(a[i], a[j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}
```

小 C 非常困惑，他想知道他的程序是否正确，并且想知道：`std::swap(a[i], a[j]);` 执行了多少次。

形式化地说：给定正整数 $n$ 与一个长度为 $n$ 的序列 $a$，如果题目背景中的程序可以将序列 $a$ 排序为#strong[严格不下降]序列，则输出 `YES`，并输出程序中 `std::swap(a[i], a[j]);` 这一条语句的运行次数，否则输出 `NO`。

定义一个长度为 $n$ 的序列 $t$ 是#strong[严格不下降]序列，当且仅当对所有 $1 lt.eq i lt.eq j lt.eq n$，都满足 $t_i lt.eq t_j$，也就是说这个序列中不存在逆序对。

== 输入格式 <输入格式-6>
每个测试点的输入数据包括两行，第一行包含一个正整数 $n$，第二行包含 $n$ 个由空格隔开的正整数 $a_0, a_1, dots, a_(n-1)$。

#pagebreak()

== 输出格式 <输出格式-6>
如果程序可以将序列 $a$ 重新排序为#strong[严格不下降]序列，则在第一行输出 `YES`，并在第二行输出一个整数，代表程序中 `std::swap(a[i], a[j]);` 这一条语句的运行次数，否则输出 `NO`。

== 样例 1 <样例-1-6>
=== 样例 1 输入 <样例-1-输入-6>
```
5
5 4 3 2 1
```

=== 样例 1 输出 <样例-1-输出-5>
```
YES
10
```

== 数据范围 <数据范围-6>
对于 100% 的数据，保证：

- $1 lt.eq n lt.eq 10^5$；
- $1 lt.eq a_i lt.eq 10^9$;
- 所有输入数据均为正整数。

== 子任务 <子任务-6>
#block[
  #set enum(numbering: "1.", start: 0)
  + （20 分）$1 lt.eq n lt.eq 10^3$；
  + （30 分）所有的 $a_i$ 均不相等。
  + （50 分）无额外限制。
]

#pagebreak()

= Problem H. 购买车券 <problem-h.-购买车券>

#figure(
  image("sparkarte.jpg", width: 66%) 
)

力量来自欢乐是 1930 年代德国的一个旅游公司，他们在本土推出了一款汽车，由费迪南德·保时捷一手设计，其宗旨是让每一个德国人民都用得上一辆汽车。为了促进德国人民购买力量来自欢乐牌汽车，德国政府推出了一种购车券：每一张券的价值是 5 帝国马克，购买的人可以通过类似集邮的方式，当其所拥有的券价值总和和一辆车同价（990 帝国马克）时，就能够兑换一辆力量来自欢乐牌汽车。然而，和梅福券一样，随着 1939 年战争的爆发，大部分的购车券都成为了空头支票，被政府用作了扩军的资本。

在探究课前，小 K 正在研究有关的历史，所以他收集了 $n$ 张购车券，并假设某些购车券之间有一定的关联关系。现在发现购车券之间一共有 $n minus 1$ 对#strong[双向的]关联关系，并且这些购车券#strong[不存在]循环的关联关系（即关联关系不成环）。

对于一张购车券，当 小 K #strong[至多]未购买一张和其相关联的购车券时，他就可以购买该购车券。当小 K 购买了所有的购车券时，他便能够兑换一辆力量来自欢乐牌汽车。

小 K 想请你帮他计算：有多少种购买购车券的方案，使得小 K 能够兑换一辆汽车。由于答案可能很大，小 K 只想知道其对 $998244353$ 取模的结果。

== 输入格式 <输入格式-7>
第一行一个正整数 $n$，含义见题目描述。

接下来 $n minus 1$ 行，每行两个正整数 $u_i comma v_i$，表示第 $u_i$ 张和第 $v_i$ 张购车券之间有一对关联关系。

== 输出格式 <输出格式-7>
共一行，包含一个整数，为购买购车券的方案数对 $998244353$ 取模的值。

== 样例 1 <样例-1-7>
=== 样例 1 输入 <样例-1-输入-7>
```
3
1 2
1 3
```

=== 样例 1 输出 <样例-1-输出-6>
```
4
```

== 样例 2 <样例-2-4>
=== 样例 2 输入 <样例-2-输入-4>
```
5
1 2
1 3
2 4
2 5
```

=== 样例 2 输出 <样例-2-输出-5>
```
28
```

#pagebreak()

== 样例 3 <样例-3-2>
=== 样例 3 输入 <样例-3-输入-2>
```
8
1 2
1 3
3 4
4 5
4 6
6 7
7 8
```

=== 样例 3 输出 <样例-3-输出-2>
```
392
```

== 样例 4 <样例-4-1>
=== 样例 4 输入 <样例-4-输入-1>
```
18
14 3
16 11
6 10
8 7
1 3
4 17
3 17
4 16
9 13
15 10
13 2
18 9
17 12
12 10
7 5
3 18
7 12
```

=== 样例 4 输出 <样例-4-输出-1>
```
289685999
```

#pagebreak()

== 提示 <提示-5>
=== 样例 1 解释 <样例-1-解释-4>

#figure(
  image("sparkarte_sample.png", width: 66%) 
)

小 K 可以先购买 $3$ 号购车券，此时对于 $1$ 号购车券，他只剩一张关联的购车券还未拥有（$2$ 号购车券），因此他能够购买 $1$ 号购车券。总共的购买顺序为 $lr((3 comma 1 comma 2))$。类似的，他也能以 $lr((2 comma 1 comma 3))$，$lr((2 comma 3 comma 1))$，$lr((3 comma 2 comma 1))$ 的顺序购买，一共 $4$ 种购买方式。

== 数据范围 <数据范围-7>
对于 100% 的数据，保证：

- $1 lt.eq n lt.eq 10^5$；
- $1 lt.eq u_i comma v_i lt.eq n$；
- $u_i eq.not v_i$；
- $lr((u_i comma v_i)) eq.not lr((u_j comma v_j))$；
- 所有输入数据均为正整数。

== 子任务 <子任务-7>
#block[
  #set enum(numbering: "1.", start: 0)
  + （13 分）$1 lt.eq n lt.eq 10$；
  + （21 分）$1 lt.eq n lt.eq 10^3$；
  + （12 分）每张购车券至多只有两张购车券相关联。
  + （12 分）存在至少一张购车券与 $n minus 1$ 张购车券相关联。
  + （42 分）无额外限制。
]

#pagebreak()

= Problem I. 花卉培育 <problem-i.-花卉培育>#figure(
  image("flower.jpg", width: 66%) 
)

小 S 是一个可爱的女孩子，她一直梦想着拥有一座美丽的花园，喜欢五颜六色的花。

这天她买了一本关于花卉培养的书，按照书中的指引，她又买了 $n$ 个花盆，从左到右依次标号 $1 comma 2 comma dots comma n$，准备在这些花盆中种下一些花；具体地，对于第 $i$ 种颜色的花盆，她可以种下不超过 $10^9$ 株花，当然也可以不种花。

小 S 注意到，为了提升花卉的美观性，书中有 $q$ 条美化花卉的秘诀；为了满足第 $j$ 条秘诀，小 S 必须使得从第 $l_j$ 个到第 $r_j$ 个花盆中，每个花盆种下花的株数的乘积模 $3$ 等于 $v_j$。书中解释说，这样做是为了让花卉的颜色呈现出一种和谐的效果，就像是一首美妙的三声部曲一样。

小 S 想请你告诉她，每种颜色的花盆到底应该种多少株花，能够满足书中的所有秘诀？当然如果确实不能满足，也请你告诉她换一本书。

== 输入格式 <输入格式-8>
第一行两个整数 $n comma q$，分别代表小 S 购买的花盆数量和书里美化花卉的秘诀数量。

接下来 $q$ 行，每行三个整数 $l_i comma r_i comma v_i$，代表每一条美化花卉的秘诀。

== 输出格式 <输出格式-8>
输出 $n$ 个整数。

- 如果存在一种种花的方案，能够满足所有的秘诀，则输出 $n$ 个整数，第 $i$ 个数为 $t$ 则代表小 S 将在第 $i$ 个花盆种下 $t$ 株花。
  
  只要你的输出能够满足题目的条件，就会被判定为正确。

- 否则，输出 $n$ 个 $minus 1$，代表不存在合法的方案。

== 样例 1 <样例-1-8>
=== 样例 1 输入 <样例-1-输入-8>
```
5 4
1 3 2
1 2 1
2 3 2
3 5 0
```

=== 样例 1 输出 <样例-1-输出-7>
```
1001011 34213 6232 0 21
```

== 样例 2 <样例-2-5>
=== 样例 2 输入 <样例-2-输入-5>
```
4 2
1 4 1
2 3 0
```

=== 样例 2 输出 <样例-2-输出-6>
```
-1 -1 -1 -1
```

== 提示 <提示-6>
=== 样例 1 解释 <样例-1-解释-5>
第 $1$ 条秘诀 $lr((1 comma 3 comma 2))$ 即 $lr((1001011 times 34213 times 6232)) med mod med 3 eq 2$。

第 $2$ 条秘诀 $lr((1 comma 2 comma 1))$ 即 $lr((1001011 times 34213)) med mod med 3 eq 1$。

第 $3$ 条秘诀 $lr((2 comma 3 comma 2))$ 即 $lr((34213 times 6232)) med mod med 3 eq 2$。

第 $4$ 条秘诀 $lr((3 comma 5 comma 0))$ 即 $lr((6232 times 0 times 21)) med mod med 3 eq 0$。

#pagebreak()

== 数据范围 <数据范围-8>
对于 100% 的数据，保证：

- $1 lt.eq n lt.eq 3 times 10^5$；
- $0 lt.eq q lt.eq 3 times 10^5$；
- $1 lt.eq l_i lt.eq r_i lt.eq n$；
- $0 lt.eq v_i lt.eq 2$；
- 所有输入数据均为整数。

== 子任务 <子任务-8>
#block[
  #set enum(numbering: "1.", start: 0)
  + （2 分）$q eq 0$；
  + （23 分）$1 lt.eq n comma q lt.eq 10$；
  + （27 分）$1 lt.eq n comma q lt.eq 2 times 10^3$；
  + （16 分）对所有 $1 lt.eq j lt.eq q$，$l_j = r_j$；
  + （32 分）无额外限制。
]

#pagebreak()

= Problem J. 繁星满天 <problem-j.-繁星满天>

#figure(
  image("starry.jpg", width: 85%) 
)

小 E 躺在草地上抬头看天空，想要看星星。天空可以视为一个位于第一象限、边界的一部分在 $x comma y$ 轴正半轴上的正方形网格，大小是 $p times p$。

形式化地，网格的四个顶点分别是 $lr((0 comma 0))$、$lr((0 comma p))$、$lr((p comma p))$、$lr((p comma 0))$，边界为折线 $lr((0 comma 0)) arrow.r.squiggly lr((0 comma p)) arrow.r.squiggly lr((p comma p)) arrow.r.squiggly lr((p comma 0)) arrow.r.squiggly lr((0 comma 0))$。

突然，小 E 获得了一种能够释放星星的超能力。具体地，每次小 E 发动超能力，他可以选择下面两种做法其中之一来释放一颗星星：

+ 选择一个#strong[整点]（横纵坐标都是整数的点），在该点释放一颗星星；

+ 选择两对#strong[已经存在]的星星，在这两对星星的连线交点处释放一颗星星。

  #strong[注意这个点可以不是整点]。

由于小 E 需要精确控制星星以组成图案，所以#strong[每次释放的星星都必须在网格内部或边界上。]

小 E 想让这片天空看上去不那么单调，所以他选择了一个点 $lr((a / b comma c / d))$（这个点的横纵坐标不大于 $1$），想在上面释放一颗星星。为了尽快达成目标，他想得到一个发动超能力的方案，使得在他发动超能力#strong[至多 $1500$ 次]以后，点 $lr((a / b comma c / d))$ 上面有一颗星星。

小 E 还要花时间调配星星的色彩，看起来这个任务就交给你了。

== 输入格式 <输入格式-9>
一行五个正整数 $p comma a comma b comma c comma d$，含义见题目描述。

#pagebreak()

== 输出格式 <输出格式-9>
第一行一个正整数 $n$，代表小 E 需要发动超能力的次数。#strong[你需要保证 $1 lt.eq n lt.eq 1500$]。

接下来 $n$ 行，第 $i$ 行有三个或五个整数，第一个整数应当为 $1$ 或 $2$：

- 若第一个整数为 $1$，即代表小 E 将在一个整点上释放一颗星星。接下来应当有两个整数 $x comma y$，你需要保证 $0 lt.eq x comma y lt.eq p$。

- 若第一个整数为 $2$，即代表小 E 将在某两对星星的连线交点处释放一颗星星。接下来应当有四个正整数 $s comma t comma u comma v$，你需要保证 $1 lt.eq s comma t comma u comma v lt i$，并且第 $s comma t$ 次发动超能力得到星星的连线，与第 $u comma v$ 次发动超能力得到星星的连线相交，同时得到交点的坐标 $x comma y$ 满足 $0 lt.eq x comma y lt.eq p$。

#strong[如果有多个满足条件的方案，你可以输出任意一个。]

== 样例 1 <样例-1-9>
=== 样例 1 输入 <样例-1-输入-9>
```
2 1 1 1 1
```

=== 样例 1 输出 <样例-1-输出-8>
```
1
1 1 1
```

== 提示 <提示-7>
为了方便实现，我们下发了一份 `fraction.hpp`，这份程序实现了一个分数类。你可以将其内容复制到你的程序中。

== 数据范围 <数据范围-9>
对 100% 的数据，保证：

- $1 lt.eq a lt.eq b lt.eq 10^7$；
- $1 lt.eq c lt.eq d lt.eq 10^7$；
- $2 lt.eq p lt.eq 10^7$；
- 所有输入数据均为正整数。

== 子任务 <子任务-9>
设 $t eq max (b comma d)$。

#block[
  #set enum(numbering: "1.", start: 0)
  + （10 分）$1 lt.eq t lt.eq 10^3$，$p gt.eq 10^7$；
  + （13 分）$1 lt.eq t lt.eq 10^6$，$p gt.eq t plus 1$；
  + （21 分）$p gt.eq ⌈ t / 2 ⌉ plus 1$；
  + （25 分）$p gt.eq ⌈ sqrt(t) ⌉ plus 2$；
  + （31 分）无额外限制。
]
