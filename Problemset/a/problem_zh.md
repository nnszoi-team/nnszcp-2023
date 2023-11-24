## 题目背景

南宁市第三中学是广西首批重点中学、广西首批示范性高中、首批普通高中新课程新教材实施国家级示范校。学校前身为 1897 年维新人士余镜清创办的南宁乌龙寺讲堂。学校目前拥有青山校区、五象校区、初中部青秀校区、初中部五象校区、初中部五象校区等 5 个校区，形成多校区集团办学模式。历经 126 年办学历史的洗礼与积淀，南宁三中以“真 • 爱教育”的办学思想和“德育为先，文理并重，崇尚一流”的办学特色饮誉华夏大地，成为莘莘学子向往的求知殿堂。

## 题目描述

为了欢迎各位新老选手的到来，南宁三中 01 社的成员们写了一句欢迎语。但是你作为一名新选手，不是很了解夹杂在欢迎语中的各种梗，你只知道 `nnsz` 是“南宁三中”的意思。

聪明的你想知道，在欢迎语中，是否存在一段连续部分（即字串）为 `nnsz`。

## 输入格式

给定一个仅包含小写英文字母且不包含空格的字符串 $ S $，代表欢迎语。

## 输出格式

如果欢迎语 $ S $ 存在一段连续部分（即字串）为 `nnsz`，输出 `yes`，否则输出 `no`。

**答案不区分大小写。**

例如，当答案为 `yes` 时，`YES`，`yEs`，`YEs` 等答案均可被判定为正确答案。

## 样例 #1

### 样例输入 #1

```
welcometonnsz
```

### 样例输出 #1

```
yes
```

## 样例 #2

### 样例输入 #2

```
nnez
```

### 样例输出 #2

```
no
```

## 样例 #3

### 样例输入 #3

```
nocommander
```

### 样例输出 #3

```
no
```

## 提示

记 $ n $ 为 $ S $ 的长度。

对于 $ 100\% $ 的数据，保证 $ 1 \le n \le 100 $，且 $ S $ 中仅包含小写英文字母。

| 子任务编号 | 限制 | 分数 |
|:-:|:-:|:-:|
| $ \textrm{Subtask 0} $ | $ n \le 3 $ | $ 45 $ |
| $ \textrm{Subtask 1} $ | $ n = 4 $ | $ 5 $ |
| $ \textrm{Subtask 2} $ | $ n \le 100 $ | $ 50 $ |
