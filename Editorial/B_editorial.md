本题为第二道签到题，按照题意直接计算答案即可，时间复杂度为 $ \mathcal{O} \left(n\right) $。

注意第二行要读入 $ n + 1 $ 个数。

- C++ 代码：

```cpp
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    ++n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int max = a[0], diff = -2e9;
    for (int i = 1; i < n; ++i) {
        diff = std::max(diff, a[i] - a[i - 1]);
        max = std::max(max, a[i]);
    }

    std::cout << max << '\n' << diff << '\n';

    return 0;
}
```

- Python 代码：

```python
n = int(input())
a = [ int(i) for i in input().split() ]
print(max(a))
b = [ a[i + 1] - a[i] for i in range(n) ]
print(max(b))
```