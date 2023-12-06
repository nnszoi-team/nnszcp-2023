## 重要结论

题目中的排序算法必定可以正常运行。（虽然它看起来很假）

所以并不能 `std::cout << "NO";` 拿 $ \textrm{45 pts} $。（笑）

## 证明

关注排序部分核心代码（这里为方便叙述换用 $ 1 $ 下标）：

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

假设 $ i = k \left(k \ge 1\right) $ 时结论成立（即序列 $ a_1, a_2, \dots, a_k $ 严格不下降），关注第 $ k + 1 $ 轮遍历的过程：

- 当 $ j < k + 1 $ 时，

    遍历过程可以分为以下步骤：

    1. 对于序列 $ a $ 中原本处于位置 $ m $ 上的元素 $ a_m $，如果 $ a_m $ 是序列 $ \{ a_1, a_2, \dots, a_k \} $ 中严格大于 $ a_{k + 1} $ 的元素中最小的一个，则 $ a_m $ 与 $ a_{k + 1} $ 互换位置。
    2. 交换后，继续寻找新的 $ a_m $。随着 $ j $ 的增大，当 $ j = k + 1 $ 时，步骤终止。

    由 $ a_m $ 的定义可知，$ a_{k + 1} $ 不可能与排在 $ a_m $ 之前的元素互换位置（否则与 $ a_m $ 的最小性相悖），从而保证了交换后的序列 $ \{ a_1, a_2, \dots, a_m \} $ 同原来一样是严格不下降的。

    一次交换后，如果 $ a_{k + 1} $ 不是序列 $ a $ 中的最大元素，那么序列 $ a_{m + 1}, \dots, a_k $ 中必定存在元素 $ a_j > a_{k + 1} $，二者又可以互换位置，直到最后 $ a_{k + 1} $ 是 $ a $ 中的最大元素为止。

    在此过程中，序列 $ a_1, a_2, \dots, a_k $ 的严格不下降性质始终不被破坏，而最后 $ a_{k + 1} $ 又是序列 $ a $ 的最大元素，故序列 $ a_1, a_2, \dots, a_{k + 1} $ 是严格不下降的。

- 当 $ j \ge k + 1 $ 时，

    因为 $ a_{k + 1} $ 是序列 $ a $ 中的最大元素，所以 $ a_j \le a_{k + 1} $，二者不可能交换位置，序列 $ a_1, a_2, \dots, a_{k + 1} $ 的严格不下降性质也不会被破坏。

综上，如果 $ i = k \left(k \ge 1\right) $ 时结论成立，那么 $ i = k + 1 $ 时结论也成立。

又因为 $ i = 1 $ 时结论成立，故对于任意正整数 $ i $，结论均成立。

证毕。

## 代码实现

从上面的证明可以看到，除了第 $ 1 $ 轮遍历，第 $ i $ 轮遍历对答案的贡献为序列 $ \{ a_1, a_2, a_{i - 1} \} $ 中比 $ a_i $ 大的**不同**元素的个数。

对于第 $ 1 $ 轮遍历，朴素维护即可。

对于其他轮次的遍历，我们只需维护一种数据结构，支持以下两种操作即可：

- 插入元素
- 查询大于某个元素的**不同**元素个数

很明显，这可以用平衡树维护。

下面给出的代码使用了有旋 Treap。

```cpp
#include <iostream>
#include <cstdlib>
#include <vector>

class Treap {
private:

	struct Node {
		Node *lc, *rc;
		int value, key;
		int size;

		Node(const int value = 0) : lc(nullptr), rc(nullptr), value(value), key(rand()), size(1) {}

		void upd_size() {
			this->size = 1;
			if (this->lc) this->size += this->lc->size;
			if (this->rc) this->size += this->rc->size;
		}
	};

	Node *root;
	
	void zig(Node *&cur) {
		Node *prev_lc = cur->lc;
		cur->lc = prev_lc->rc;
		prev_lc->rc = cur;

		cur = prev_lc;
		
		cur->rc->upd_size();
		cur->upd_size();
	}

	void zag(Node *&cur) {
		Node *prev_rc = cur->rc;
		cur->rc = prev_rc->lc;
		prev_rc->lc = cur;

		cur = prev_rc;

		cur->lc->upd_size();
		cur->upd_size();
	}

	void insert(Node *&cur, const int value) {
		if (!cur) {
			cur = new Node(value);
			return;
		}
		if (cur->value == value)
			return;

		if (cur->value > value) {
			insert(cur->lc, value);
			if (cur->key < cur->lc->key)
				zig(cur);
		}
		else {
			insert(cur->rc, value);
			if (cur->key < cur->rc->key)
				zag(cur);
		}
		cur->upd_size();
	}
	
	int query(const Node *cur, const int value) const {
		if (!cur)
			return 0;
		if (cur->value < value)
			return query(cur->rc, value);
		if (cur->value == value)
			return cur->rc ? cur->rc->size : 0;
		return query(cur->lc, value) + 1 + (cur->rc ? cur->rc->size : 0);
	}

	void del(Node *&cur) {
		if (!cur) return;
		del(cur->lc), del(cur->rc);
		delete cur;
		cur = nullptr;
	}

public:

	Treap() : root(nullptr) {}
	~Treap() { del(root); }
	void insert(const int value) { insert(root, value); }
	int query(const int value) const { return query(root, value); }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int& i : a) std::cin >> i;
	
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[0])
			continue;

		std::swap(a[0], a[i]);
		++ans;
	}
	
	Treap treap;
	treap.insert(a[0]);
	for (int i = 1; i < n; ++i) {
		ans += treap.query(a[i]);
		treap.insert(a[i]);
	}
	
	std::cout << "YES\n" << ans << '\n';
	
	return 0;
}
```

我们也可以通过其他方式支持以上操作。

将序列 $ a $ 中元素通过离散化映射到区间 $ [1, m] $ 中（$ m $ 为序列 $ a $ 中不同元素的个数）。设元素 $ a_i $ 映射为 $ j $，如果元素 $ a_i $ 已经被插入到数据结构中，则将区间 $ [1, m] $ 中下标为 $ j $ 的元素更新为 $ 1 $，否则为 $ 0 $。对于查询操作，只需查询区间 $ [j + 1, m] $ 的区间和即可。

区间内单点修改和区间求和操作，用树状数组维护再适合不过了。

代码如下：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Bit {
private:

	int n;
	std::vector<int> bit;

	int query(const int idx) const {
		int res = 0;
		for (int i = idx; i; i -= i & -i)
			res += bit[i];
		return res;
	}

public:

	Bit(const int n = 0) : n(n), bit(std::vector<int>(n + 1)) {}

	void add(const int idx) {
		for (int i = idx; i <= n; i += i & -i)
			++bit[i];
	}

	int query(const int l, const int r) const {
		return query(r) - query(l - 1);
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int& i : a) std::cin >> i;
	
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[0])
			continue;

		std::swap(a[0], a[i]);
		++ans;
	}

	std::vector<int> b = a;
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());
	
	int m = b.size();
	std::vector<bool> added(m + 1);
	Bit bit(m);

	bit.add(m);
	added[m] = true;
	for (int i = 1; i < n; ++i) {
		int idx = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		if (!added[idx]) {
			bit.add(idx);
			added[idx] = true;
		}
		ans += bit.query(idx + 1, m);
	}
	
	std::cout << "YES\n" << ans << '\n';
	
	return 0;
}
```

线段树同样可以维护以上信息。

代码如下：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class SegmentTree {
private:

	struct Node {
		Node *lc, *rc;
		int l, r;
		int sum;

		Node(const int l = 0, const int r = 0)
		: lc(nullptr), rc(nullptr), l(l), r(r), sum(0) {}

		void push_up() {
			this->sum = 0;
			if (this->lc) this->sum += this->lc->sum;
			if (this->rc) this->sum += this->rc->sum;
		}
	};

	Node *root;

	void build(Node *&cur, const int l, const int r) {
		cur = new Node(l, r);
		if (l == r) return;

		int mid = (l + r) >> 1;
		build(cur->lc, l, mid);
		build(cur->rc, mid + 1, r);
	}

	void modify(Node *cur, const int idx) {
		if (cur->l == cur->r) { cur->sum = 1; return; }

		int mid = (cur->l + cur->r) >> 1;
		modify(idx <= mid ? cur->lc : cur->rc, idx);
		cur->push_up();
	}

	int query(Node *cur, const int l, const int r) const {
		if (l <= cur->l && cur->r <= r) return cur->sum;

		int mid = (cur->l + cur->r) >> 1;
		int res = 0;
		if (l <= mid) res += query(cur->lc, l, r);
		if (r > mid) res += query(cur->rc, l, r);
		return res;
	}

	void del(Node *&cur) {
		if (!cur) return;
		del(cur->lc), del(cur->rc);
		delete cur;
		cur = nullptr;
	}

public:

	SegmentTree() : root(nullptr) {}
	SegmentTree(const int n) : root(nullptr) { build(root, 1, n); }
	~SegmentTree() { del(root); }
	void modify(const int idx) { modify(root, idx); }
	int query(const int l, const int r) const { return query(root, l, r); }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int& i : a) std::cin >> i;
	
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[0])
			continue;

		std::swap(a[0], a[i]);
		++ans;
	}

	std::vector<int> b = a;
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());
	
	int m = b.size();
	SegmentTree segment_tree(m);
	segment_tree.modify(m);
	for (int i = 1; i < n; ++i) {
		int idx = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		segment_tree.modify(idx);
		ans += segment_tree.query(idx + 1, m);
	}
	
	std::cout << "YES\n" << ans << '\n';
	
	return 0;
}
```

三份代码的时间复杂度均为 $ \mathcal{O}(n\log n) $。

综合对比三者，树状数组解法代码短，常数小，为最优解。

对于本题的 Python 标程，这里仅给出树状数组解法：

```python
from bisect import bisect_right

class Bit:
    
    def __init__(self, n: int) -> None:
        self.n = n
        self.bit = [0] * (n + 1)
    
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
    b = sorted(list(set(a)))

    res = 0
    for i in range(n):
        if a[i] <= a[0]:
            continue
        res += 1
        a[0], a[i] = a[i], a[0]
    
    m = len(b)
    bit = Bit(m)
    bit.add(m)
    v = [False] * (m + 1)
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

## 彩蛋

题目成型后，笔者偶然发现了[这篇论文](https://arxiv.org/pdf/2110.01111.pdf)，论文将该排序算法命名为 $ \texttt{ICan'tBelieveItCanSort} $，并证明了这个~~有趣而没用的~~算法的正确性，还探讨了该排序算法与其他常见 $ \mathcal{O}\left(n^2\right) $ 排序算法的联系与区别。在这里分享给大家，希望对大家有帮助。
