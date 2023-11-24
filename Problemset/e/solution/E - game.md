题目要求构造满足以下 $ 3 $ 个条件的矩阵：

1. 矩阵中的元素均为自然数，且在区间 $ [0, k] $ 内。

2. 矩阵中的元素各不相同。

3. 从矩阵中选出 $ n $ 个元素，使得每一行有且仅有一个元素被选出，且每一列有且仅有一个元素被选出；对于每一种符合上述规则的选择元素的方案，选出的元素总和均为 $ k $。

可以先考虑什么时候无解。

构造一个元素取遍 $ [0, n^2 - 1] $ 的矩阵，并令其元素从左到右，从上到下升序排列，这显然是同时满足条件 $ 1 $ 和条件 $ 2 $ 的元素最小的矩阵。

对于该矩阵，使得其符合条件 $ 3 $ 的 $ k = \dfrac{n \times (n^2 - 1)}{2} = \dfrac{(n - 1) \times n \times (n + 1)}{2} $。

设 $ k_{min} = \dfrac{(n - 1) \times n \times (n + 1)}{2} $，如果所给的 $ k < k_{min} $，即为无解，因为我们无法构造出元素更小的矩阵。

在同时满足条件 $ 1 $ 和条件 $ 2 $ 的基础上，同时满足以下三点的矩阵即为符合题意的矩阵。

1. 至少存在一个符合题意的选择元素的方案。

2. 对于矩阵中的任意两行，每一列上的两个元素的差都相等。

3. 对于矩阵中的任意两列，每一行上的两个元素的差都相等。

简要证明如下：

设一个符合题意的选择元素的方案中选择了元素 $ A_{i, j} $ 和元素 $ A_{x, y} \left(i \neq x, j \neq y\right) $。

由上述的第 $ 2 $ 点和第 $ 3 $ 点可知：
$$
A_{i, j} + A_{x, y} = A_{i, y} + A_{x, j}
$$

如果在这个方案中，不选择元素 $ A_{i, j} $ 和元素 $ A_{x, y} $，而是选择元素 $ A_{i, y} $ 和元素 $ A_{x, j} $，我们就得到了一个新的符合题意的选择方案。

所以，我们可以由任意一个符合题意的选择元素的方案，按以上方法得到所有符合题意的选择元素的方案。

我们发现，前文提到的元素取遍 $ [0, n^2 - 1] $ 的矩阵，已经满足了上述的第 $ 2 $ 点和第 $ 3 $ 点。我们只需在其基础上做一定改动，使其满足第 $ 1 $ 点即可。

不难发现，把第 $ n $ 行的所有元素都加上 $ k - k_{min} $ 即可。

C++ 标程：

```cpp
#include <iostream>

void solve() {

    int n, k;
    std::cin >> n >> k;
    
    int k_min = (n - 1) * n * (n + 1) / 2;
    if (k < k_min) {
        std::cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << i * n + j + (i == n - 1 ? k - k_min : 0) << ' ';
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) solve();

    return 0;
}
```

Python 标程：

```python
for test_case in range(int(input())):
    n, k = [ int(i) for i in input().split() ]
    
    k_min = (n - 1) * n * (n + 1) // 2
    if k < k_min:
        print(-1)
        continue

    for i in range(n):
        for j in range(n):
            print(i * n + j + (k - k_min if i == n - 1 else 0), end = " ")
        print()    
```
