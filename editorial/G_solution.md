## 重要结论

题目中的排序算法必定可以正常运行。（虽然它看起来很假）

所以并不能 `cout << "NO";` 拿 $ 45 $ pts。（笑）

## 证明

关注排序部分核心代码：

```cpp
for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= n; ++j) {
		if (a[i] < a[j]) {
			std::swap(a[i], a[j]);
		}
	}
}
```

定义 $ i $ 不变，$ j $ 遍历 $ 1 $ 到 $ n $ 的一段程序运行过程为**一轮遍历**，并称 $ i = k $ 时的一轮遍历为**第 $ k $ 轮遍历**。

该算法的正确性基于如下的重要结论：

- 在第 $ i $ 轮遍历结束后，序列 $ a $ 的子序列 $ \{ a_1, a_2, \dots, a_i \} $ 是严格不下降的。

将 $ i = n $ 代入上述结论，即为

- 在第 $ n $ 轮遍历结束后，序列 $ a $ 是严格不下降的。

即算法具有正确性。

所以，我们只需证明上述结论，算法的正确性即可得证。

用数学归纳法证明如下：

可以看出，在一轮遍历后，有
$$
a_i = \max_{k = 1}^n \{ a_k \}
$$

即序列 $ a $ 中的最大元素处于序列的第 $ i $ 个位置上。

第 $ 1 $ 轮遍历结束后，$ a_1 $ 必为序列 $ a $ 的最大元素。

此时，序列 $ \{ a_1 \} $ 只有一个元素，满足严格不下降。

即在 $ i = 1 $ 时上述结论成立。

假设 $ i = k \text{ } (k \ge 1) $ 时结论成立（即序列 $ a_1, a_2, \dots, a_k $ 严格不下降），关注第 $ k + 1 $ 轮遍历的过程：

- 当 $ j < k + 1 $ 时，

    遍历过程可以分为以下步骤：

    1. 对于序列 $ a $ 中原本处于位置 $ m $ 上的元素 $ a_m $，如果 $ a_m $ 是序列 $ \{ a_1, a_2, \dots, a_k \} $ 中严格大于 $ a_{k + 1} $ 的元素中最小的一个，则 $ a_m $ 与 $ a_{k + 1} $ 互换位置。
    2. 交换后，继续寻找新的 $ a_m $。随着 $ j $ 的增大，当 $ j = k + 1 $ 时，步骤终止。

    由 $ a_m $ 的定义可知，$ a_{k + 1} $ 不可能与排在 $ a_m $ 之前的元素互换位置（否则与 $ a_m $ 的最小性相悖），从而保证了交换后的序列 $ \{ a_1, a_2, \dots, a_m \} $ 同原来一样是严格不下降的。

    一次交换后，如果 $ a_{k + 1} $ 不是序列 $ a $ 中的最大元素，那么序列 $ a_{m + 1}, \dots, a_k $ 中必定存在元素 $ a_j > a_{k + 1} $，二者又可以互换位置，直到最后 $ a_{k + 1} $ 是 $ a $ 中的最大元素为止。

    在此过程中，序列 $ a_1, a_2, \dots, a_k $ 的严格不下降性质始终不被破坏，而最后 $ a_{k + 1} $ 又是序列 $ a $ 的最大元素，故序列 $ a_1, a_2, \dots, a_{k + 1} $ 是严格不下降的。

- 当 $ j \ge k + 1 $ 时，

    因为 $ a_{k + 1} $ 是序列 $ a $ 中的最大元素，所以 $ a_j \le a_{k + 1} $，二者不可能交换位置，序列 $ a_1, a_2, \dots, a_{k + 1} $ 的严格不下降性质也不会被破坏。

综上，如果 $ i = k \text{ } (k \ge 1) $ 时结论成立，那么 $ i = k + 1 $ 时结论也成立。

又因为 $ i = 1 $ 时结论成立，故对于任意正整数 $ i $，结论均成立。

证毕。

## 代码实现

从上面的证明可以看到，除了第 $ 1 $ 轮遍历，每一轮遍历对答案的贡献为序列 $ \{ a_1, a_2, a_{i - 1} \} $ 中比 $ a_i $ 大的**不同**元素的个数。

对于第 $ 1 $ 轮遍历，朴素维护即可。

对于其他轮次的遍历，我们只需维护一种数据结构，支持以下两种操作即可：

- 插入元素
- 查询大于某个元素的**不同**元素个数

很明显，这可以用平衡树维护。

下面给出的代码使用了 Treap。

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

const int inf = 1 << 30;
const int max_n = 2e5 + 10;

struct Node {
	int lc, rc;
	int value, dat;
	int size;
};

struct Treap {
	
	int root;
	int cnt_node = 0;
	Node node[max_n];
	
	void new_node(const int value);
	void update(const int idx);
	void build();
	
	void zig(int & father);
	void zag(int & father);
	void insert(const int value, int & cur);
	
	int query(const int value, const int cur);
};

int a[max_n];
Treap treap;

int main() {
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		if (a[i] <= a[1]) {
			continue;
		}
		++ans;
		swap(a[i], a[1]);
	}
	
	treap.build();
	treap.insert(a[1], treap.root);
	for (int i = 2; i <= n; ++i) {
		treap.insert(a[i], treap.root);
		ans += treap.query(a[i], treap.root) - 3;
	}
	
	printf("YES\n%lld\n", ans);
	
	return 0;
}

void Treap::new_node(const int value) {
	node[++cnt_node].value = value;
	node[cnt_node].dat = rand();
	node[cnt_node].size = 1;
}

void Treap::update(const int idx) {
	node[idx].size = node[node[idx].lc].size + node[node[idx].rc].size + 1;
}

void Treap::build() {
	new_node(inf);
	new_node(-inf);
	root = 1;
	node[root].rc = 2;
	update(root);
}

void Treap::zig(int & father) {
	int child = node[father].lc;
	
	node[father].lc = node[child].rc;
	node[child].rc = father;
	
	father = child;
	
	update(node[father].rc);
	update(father);
}

void Treap::zag(int & father) {
	int child = node[father].rc;
	
	node[father].rc = node[child].lc;
	node[child].lc = father;
	
	father = child;
	
	update(node[father].lc);
	update(father);
}

void Treap::insert(const int value, int & cur) {
	if (!cur) {
		new_node(value);
		cur = cnt_node;
		return;
	}
	if (value == node[cur].value) {
		return;
	}
	
	if (value < node[cur].value) {
		insert(value, node[cur].lc);
		if (node[cur].dat < node[node[cur].lc].dat) {
			zig(cur);
		}
	}
	else {
		insert(value, node[cur].rc);
		if (node[cur].dat < node[node[cur].rc].dat) {
			zag(cur);
		}
	}
	update(cur);
}

int Treap::query(const int value, const int cur) {
	if (value > node[cur].value) {
		return query(value, node[cur].rc);
	}
	if (value == node[cur].value) {
		return node[node[cur].rc].size + 1;
	}
	return query(value, node[cur].lc) + node[node[cur].rc].size + 1;
}
```

我们也可以通过其他方式支持以上操作。

将序列 $ a $ 中元素通过离散化映射到区间 $ [1, m] $ 中（$ m $ 为序列 $ a $ 中不同元素的个数）。设元素 $ a_i $ 映射为 $ j $，如果元素 $ a_i $ 已经被插入到数据结构中，则将区间 $ [1, m] $ 中下标为 $ j $ 的元素更新为 $ 1 $，否则为 $ 0 $。对于查询操作，只需查询区间 $ [j + 1, m] $ 的区间和即可。

区间内单点修改和区间求和操作，用树状数组维护再适合不过了。

代码如下：

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 2e5 + 10;

int n, m;
int a[max_n], b[max_n];
bool added[max_n];
int bit[max_n];

void add(const int idx);
int query(const int idx);

int main() {
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - (b + 1);
	
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		if (a[i] <= a[1]) {
			continue;
		}
		++ans;
		swap(a[i], a[1]);
	}
	
	added[m] = true;
	add(m);
	for (int i = 2; i <= n; ++i) {
		int idx = lower_bound(b + 1, b + m + 1, a[i]) - b;
		if (!added[idx]) {
			add(idx);
			added[idx] = true;
		}
		ans += query(m) - query(idx);
	}
	
	printf("YES\n%lld\n", ans);
	
	return 0;
}

void add(const int idx) {
	for (int i = idx; i <= m; i += i & -i) {
		++bit[i];
	}
}

int query(const int idx) {
	int res = 0;
	for (int i = idx; i; i -= i & -i) {
		res += bit[i];
	}
	return res;
}
```

线段树同样可以维护以上信息。

代码如下：

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 2e5 + 10;

struct Node {
	int l, r;
	int sum;
};

struct SegmentTree {
	
	Node node[max_n << 2];
	
	void build(const int l, const int r, const int cur = 1);
	void update(const int idx, const int cur = 1);
	int query(const int l, const int r, const int cur = 1);
};

int n, m;
int a[max_n], b[max_n];
SegmentTree segment_tree;

int main() {
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - (b + 1);
	
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		if (a[i] <= a[1]) {
			continue;
		}
		++ans;
		swap(a[i], a[1]);
	}
	
	segment_tree.build(1, n);
	segment_tree.update(m);
	for (int i = 2; i <= n; ++i) {
		ans += segment_tree.query(upper_bound(b + 1, b + m + 1, a[i]) - b, m);
		segment_tree.update(lower_bound(b + 1, b + m + 1, a[i]) - b);
	}
	
	printf("YES\n%lld\n", ans);
	
	return 0;
}

void SegmentTree::build(const int l, const int r, const int cur) {
	node[cur].l = l;
	node[cur].r = r;
	if (l == r) {
		return;
	}
	
	int mid = l + r >> 1;
	build(l, mid, cur << 1);
	build(mid + 1, r, cur << 1 | 1);
}

void SegmentTree::update(const int idx, const int cur) {
	if (node[cur].l == node[cur].r) {
		node[cur].sum = 1;
		return;
	}
	
	int mid = node[cur].l + node[cur].r >> 1;
	if (idx <= mid) {
		update(idx, cur << 1);
	}
	else {
		update(idx, cur << 1 | 1);
	}
	node[cur].sum = node[cur << 1].sum + node[cur << 1 | 1].sum;
}

int SegmentTree::query(const int l, const int r, const int cur) {
	if (l <= node[cur].l && node[cur].r <= r) {
		return node[cur].sum;
	}
	
	int mid = node[cur].l + node[cur].r >> 1;
	int res = 0;
	if (l <= mid) {
		res += query(l, r, cur << 1);
	}
	if (r > mid) {
		res += query(l, r, cur << 1 | 1);
	}
	return res;
}
```

三份代码的时间复杂度均为 $ \mathcal{O}(n\log n) $。

综合对比三者，树状数组解法代码短，常数小，为最优解。

Python 语言由于本身常数较大，只有树状数组解法可以通过。

```python
from bisect import bisect_right

class Bit:
    
    def __init__(self, n: int) -> None:
        self.n = n
        self.bit = [ 0 for i in range(n + 1) ]
    
    def add(self, idx: int) -> None:
        while 0 < idx <= self.n:
            self.bit[idx] += 1
            idx += idx & -idx
    
    def query(self, idx: int) -> int:
        res = 0
        while idx > 0:
            res += self.bit[idx]
            idx -= idx & -idx
        return res


if __name__ == "__main__":

    n = int(input())
    a = [ int(i) for i in input().split() ]
    
    b = list(set(a))
    b.sort()

    res = 0
    for i in range(n):
        if a[i] <= a[0]:
            continue
        res += 1
        a[0], a[i] = a[i], a[0]
    
    m = len(b)
    bit = Bit(m)
    bit.add(m)
    v = [ False for i in range(m + 1) ]
    v[m] = True

    for i in range(1, n):
        idx = bisect_right(b, a[i])
        res += bit.query(m) - bit.query(idx)
        if v[idx]:
            continue
        bit.add(idx)
        v[idx] = True

    print(f"YES\n{res}")
```
