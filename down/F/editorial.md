![](https://pic.imgdb.cn/item/65603202c458853aef9e4f2e.png)

设 $ \mathrm{OP} = a, \mathrm{AP} = b = k - a $，则 $ \mathrm{BP} = ab, \mathrm{CP} = 1 $。

由 $ \mathrm{OA} \perp \mathrm{BC} $ 可知，
$$
\begin{aligned}
    \mathrm{OB}^2 + \mathrm{AC}^2 &= \mathrm{OP}^2 + \mathrm{AP}^2 + \mathrm{BP}^2 + \mathrm{CP}^2 \\
    &= a^2 + b^2 + a^2b^2 + 1 \\
    &= \left(a + b\right)^2 - 2ab + a^2b^2 + 1 \\
    &= k^2 + \left(ab - 1\right)^2
\end{aligned}
$$

由上式可知，当 $ \left(ab - 1\right)^2 $ 最大时，$ \mathrm{OB}^2 + \mathrm{AC}^2 $ 取到最大值。

分两种情况讨论：

- $ \left(ab - 1\right) $ 最小（等价于 $ \mathrm{BP} $ 长度最小）：

点 $ \mathrm{P} $ 与点 $ \mathrm{O} $ 或点 $ \mathrm{A} $ 重合，$ \left(ab - 1\right) $ 取到最小值 $ -1 $，此时

$$
\mathrm{OB}^2 + \mathrm{AC}^2 = k^2 + 1
$$

- $ \left(ab - 1\right) $ 最大（等价于 $ \mathrm{BP} $ 长度最大）：

当点 $ \mathrm{P} $ 在抛物线对称轴上时，$ \mathrm{BP} $ 长有最大值 $ \dfrac{k^2}{4} $，故

$$
\begin{aligned}
    \mathrm{OB}^2 + \mathrm{AC}^2 &= k^2 + \left(\frac{k^2}{4} - 1\right)^2 \\ 
    &= 4 \times \frac{k^2}{4} + \left(\frac{k^2}{4} - 1\right)^2 \\
    &= \left(\frac{k^2}{4} + 1\right)^2
\end{aligned}
$$

综上有

$$
ans = \max\left(k^2 + 1, \left(\dfrac{k^2}{4} + 1\right)^2\right)
$$

C++ 标程：

```cpp
#include <iostream>
#include <cmath>

void solve() {
    
    double a, b; std::cin >> a >> b;
    
    double k = a / b;
    double ans = std::max(pow(k, 2) + 1, pow(pow(k, 2) * 0.25 + 1, 2));

    std::cout << std::fixed << ans << '\n';
}

int main() {
    
    int T; std::cin >> T;
    while (T--) solve();

    return 0;
}
```

Python 标程：

```python
for test_case in range(int(input())):
    a, b = [ int(i) for i in input().split() ]
    k = a / b
    ans = max((k * k / 4 + 1) ** 2, k * k + 1)
    print(ans)
```
