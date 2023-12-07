本题是模拟题。减小编码难度、减少码量从而快速解决本题，才能拥有更多的时间解决后面的题目。

本题 C++ 标程仅约 700 Byte，Python 标程仅约 400 Byte，它们都用到了以下优化技巧来减小码量。

- 使用 `tuple` 而非 `struct` 或 `class` 表示考生。

- 运用位运算技巧，仅用一个整数即可表示考生各科 $ \texttt{A+} $ 情况。

运用位运算技巧将考生各科 $ \texttt{A+} $ 情况压缩成一个整数，即可以方便地在 `tuple` 中存储考生的数据，又可以通过直接比较整数的大小来分出成绩的优劣。

而且，`tuple` 自带关键字比较功能，我们无需重载运算符或手写 `cmp()` 函数，进一步减小了码量。


C++ 标程：

```cpp
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
	
	std::vector<int> l(7);
	for (int i = 0; i < 7; ++i)
		std::cin >> l[i];
	
	int n, m; std::cin >> n >> m;
	std::vector<std::tuple<int, int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = 0; j < 7; ++j) {
			int v;
			std::cin >> v;

			s += v;
			if (j == 6 || v < l[j])
				continue;
			
			++std::get<1>(a[i]);
			std::get<2>(a[i]) |= 1 << (5 - j);
		}
		std::get<0>(a[i]) = s >= l[6];
	}
	
	std::sort(a.begin(), a.end(), std::greater<std::tuple<int, int, int>>());
	while (m < n && a[m] == a[m - 1]) ++m;
	
	std::cout << m << std::endl;
	
	return 0;
}
```

Python 标程：

```python
l = [ int(i) for i in input().split() ]
n, m = [ int(i) for i in input().split() ]

a = []
for i in range(n):
    s = [ int(i) for i in input().split() ]
    t = [ sum(s) >= l[6], 0, 0 ]
    
    for j in range(6):
        if s[j] < l[j]:
            continue
        t[1] += 1
        t[2] |= 1 << (5 - j)
    a.append(tuple(t))

a.sort(reverse = True)
while m < n and a[m] == a[m - 1]:
    m += 1

print(m)
```
