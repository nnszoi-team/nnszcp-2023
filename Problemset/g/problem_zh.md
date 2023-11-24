## 题目背景


某日，小陈同学翻出了不知多久以前写的老代码，内容如下：

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
		std::cout << a[i] << ' ';
	}

	return 0;
}
```

小陈同学非常困惑，他想知道他的程序是否正确，并且想知道：`std::swap(a[i], a[j]);` 执行了多少次。

## 题目描述

给定正整数 $ n $ 与一个长度为 $ n $ 的序列 $ a $，如果题目背景中的程序可以将序列 $ a $ 排序为**严格不下降**序列，则输出 `YES`，并输出程序中 `std::swap(a[i],a[j]);` 这一条语句的运行次数，否则输出 `NO`。

## 输入格式

每个测试点的输入数据包括两行，第一行包含一个正整数 $ n $，第二行包含 $ n $ 个由空格隔开的正整数 $ a_1, a_2, \dots, a_n $。

## 输出格式

如果题目背景中的程序可以将序列 $ a $ 重新排序为**严格不下降**序列，则在第一行输出 `YES`，并在第二行输出一个整数，代表程序中 `swap(a[i],a[j]);` 这一条语句的运行次数，否则输出 `NO`。

## 样例 #1

### 样例输入 #1

```
5
5 4 3 2 1
```

### 样例输出 #1

```
YES
10
```

## 提示

对于 $100\%$ 的数据，有 $ 1 \le n \le 2 \times 10^5$，$1 \le a_i \le 10^9 $。

| 子任务编号 | 限制 | 特殊性质 | 分数 |
|:---:|:---:|:---:|:---:|
| $\textrm{Subtask 0}$ | $1 \le n \le {10}^3$ | 无 | $ 20 $ |
| $\textrm{Subtask 1}$ | $1 \le n \le 2 \times {10}^5$ | A | $ 30 $ |
| $\textrm{Subtask 2}$ | $1 \le n \le 2 \times {10}^5$ | 无 | $ 50 $ |

- 特殊性质 A：对 $1 \le i < j \le n$，$a_i \neq a_j$。

