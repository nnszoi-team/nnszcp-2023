- 对于 $ \textrm{Subtask 0} $：

对于每匹天马，枚举每一对建筑，并判断它是否能在该对建筑之间穿梭。时间复杂度为 $ \mathcal{O} \left(n^2m\right) $。

- 对于 $ \textrm{Subtask 1} $：

由 $ s_i > 0 $ 可知，每一匹天马均可在建筑中任意穿梭，故答案为 $ \frac{n(n - 1)}{2} $。

- 对于 $ \textrm{Subtask 2} $：

预处理每对建筑之间的高度差，并将其升序排序。对于每匹天马，在高度差数组中通过二分查找得到答案。

预处理高度差并排序的时间复杂度为 $ \mathcal{O} \left(n^2 \log{n^2} \right) $，进行 $ m $ 次二分查找的时间复杂度为 $ \mathcal{O} \left(m \log{n^2} \right) $，故总时间复杂度为 $ \mathcal{O} \left(\left(n^2 + m\right) \log{n^2} \right) $，可以通过。

- C++ 代码：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    int n, m;
    std::cin >> n >> m;

    std::vector <int> h(n), dh;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> h[i];
        for (int j = 0; j < i; ++j)
            dh.push_back(std::abs(h[i] - h[j]));
    }
    
    std::sort(dh.begin(), dh.end());

    while (m--)
    {
        int s;
        std::cin >> s;
        
        int res = std::upper_bound(dh.begin(), dh.end(), s) - dh.begin();
        std::cout << res << std::endl;
    }

    return 0;
}
```

- Python 代码：

```python
from bisect import bisect_right

n, m = [ int(i) for i in input().split() ]
h = [ int(i) for i in input().split() ]
s = [ int(i) for i in input().split() ]

dh = [ abs(h[i] - h[j]) for i in range(n) for j in range(i) ]
dh.sort()

for i in s:
    print(bisect_right(dh, i))
```

时间复杂度更优的算法不在本题的讨论范围内。
