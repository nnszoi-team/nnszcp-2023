## 题意简述

给定一颗无根树，每次操作删去一个叶子结点，不断进行操作直至树为空。

求出操作方案数对 $ 998,244,353 $ 取模的值。

叶子结点定义为度数为 $ 1 $ 的结点。

- 对于 $ \textrm{Subtask 0} $：

暴力搜索，代码如下：

```cpp
#include <iostream>

const int max_node_num = 2e5 + 10;

int head[max_node_num];
struct Edge { int next, to; } edge[max_node_num << 1];
int edge_idx = 1;

int node_num;
int degree[max_node_num];
bool used[max_node_num << 1];

int ans = 0;

void add_edge(const int from, const int to);
void dfs(const int cnt_node);

int main() {

	std::cin >> node_num;
	for (int i = 1, from, to; i <= node_num - 1; ++i) {
		std::cin >> from >> to;
		add_edge(from, to), add_edge(to, from);
		++degree[from], ++degree[to];
	}

	dfs(1);
	std::cout << ans << '\n';

    return 0;
}

void add_edge(const int from, const int to) {
	edge[++edge_idx].to = to;
	edge[edge_idx].next = head[from];
	head[from] = edge_idx;
}

void dfs(const int cnt_node) {
	if (cnt_node >= node_num) { ++ans; return; }

	for (int from = 1; from <= node_num; ++from) {
		if (degree[from] != 1)
			continue;
		
        for (int i = head[from]; i; i = edge[i].next) {
			if (used[i]) continue;
			
            int to = edge[i].to;
			used[i] = used[i ^ 1] = true;
			--degree[from], --degree[to];

			dfs(cnt_node + 1);
            
			used[i] = used[i ^ 1] = false;
			++degree[from], ++degree[to];
		}
	}
}
```

- 对于 $ \textrm{Subtask 1} $：

我们用 $ \operatorname{tree} \left(u\right) $ 表示以结点 $ u $ 为根的子树，用 $ \operatorname{size} \left(u\right) $ 表示 $ \operatorname{tree} \left(u\right) $ 的大小，用 $ v_i $ 表示结点 $ u $ 的第 $ i $ 个儿子（即直接相连的子结点），用 $ \operatorname{cnt} \left(u\right) $ 表示结点 $ u $ 的儿子数量。

设 $ f\left(u, i\right) $ 表示**删去 $ \operatorname{tree} \left(v_{1, 2, \dots, i}\right) $** 的方案数。我们**钦定在 $ \operatorname{tree} \left(u\right) $ 中，$ u $ 是最后被删去的结点**，则删去 $ \operatorname{tree} \left(u\right) $ 的方案数为 $ f\left(u, \operatorname{cnt} \left(u\right)\right) $。

$ f\left(u, i\right) $ 可以从 $ f\left(u, i - 1\right) $ 转移过来，这相当于合并删去 $ \operatorname{tree} \left(v_{1, 2, \dots, i - 1}\right) $ 的操作序列和删去 $ \operatorname{tree} \left(v_i\right) $ 的操作序列。

可以得到以下状态转移方程：

$$
f\left(u, i\right) = f\left(u, i\right)
		  			 \times f\left(v,\operatorname{cnt} \left(v\right)\right) 
		  			 \times \begin{pmatrix}
					 			\sum_{j = 1}^i \operatorname{size} \left(v_j\right) \\
					 			\sum_{j = 1}^{i - 1} \operatorname{size} \left(v_j\right) \\
				     		\end{pmatrix}
$$

其中 $ \begin{pmatrix} \sum_{j = 1}^i \operatorname{size}\left(v_j\right) \\ \sum_{j = 1}^{i - 1} \operatorname{size}\left(v_j\right) \\ \end{pmatrix} $ 表示**将较短的序列插入较长的序列**的方案数，$ f\left(u, i\right) $ 和 $ f\left(v,\operatorname{cnt} \left(v\right)\right) $ 各自表示**两个序列内部排列**的方案数。

从上式可以看出，$ f\left(u, i\right) $ 只与 $ f\left(u, i - 1\right) $ 有关，故我们可以进行滚动数组优化。

设 $ f\left(u\right) $ 表示删去 $ \operatorname{tree} \left(u\right) $ 的方案数，则状态转移方程为：

$$
f\left(u\right) \gets f\left(u\right) 
		  		\times f\left(v\right) 
		  		\times \begin{pmatrix}
						   \sum_{j = 1}^i \operatorname{size} \left(v_j\right) \\
						   \sum_{j = 1}^{i - 1} \operatorname{size} \left(v_j\right) \\
				 	   \end{pmatrix}
$$

由于每个结点的答案只会转移到其父亲的答案中，故整棵树的 dp 过程中只会发生 $ n - 1 $ 次状态转移。在预处理组合数后，单次转移的时间复杂度为 $ \mathcal{O} \left(1\right) $。故对整棵树进行 dp 的时间复杂度是 $ \mathcal{O} \left(n\right) $。

由于每个结点都可以成为根节点（也是整棵树中最后被删去的结点），故我们需要将上述 dp 过程进行 $ n $ 次，并将答案累加。故总时间复杂度为 $ \mathcal{O} \left(n^2\right) $。

dp 部分代码如下：

```cpp
void solve(const int cur, const int fa) {
    size[cur] = 1, dp[cur] = 1;
    for (const int to : graph[cur]) {
        if (to == fa) continue;

        solve(to, cur);
        dp[cur] = (long long)dp[cur] * dp[to] % mod * C(size[cur] + size[to] - 1, size[cur] - 1) % mod;
        size[cur] += size[to];
    }
}
```

在 `main()` 函数中：

```cpp
int res = 0;
for (int i = 0; i < n; ++i) {
	solve(i, 0);
	res = (res + dp[i]) % mod;
}

std::cout << res << std::endl;
```

- 对于 $ \textrm{Subtask 2} $：

由于整棵树是一条链，在删除前 $ n - 1 $ 个结点时，树上都恰好有 $ 2 $ 个叶子结点，故答案为 $ 2^{n - 1} $。

```python
print(pow(2, int(input()) - 1, 998244353))
```

- 对于 $ \textrm{Subtask 3} $：

在删除第 $ i \text{ } \left(i \le n - 2\right) $ 个结点时，树上有 $ n - i $ 个叶子结点；在删除第 $ n - 1 $ 个结点时，树上有 $ 2 $ 个叶子结点。

故答案为：

$$
(n - 1) \times (n - 2) \times \cdots \times 3 \times 2 \times 2 \times 1 = (n - 1)! \times 2
$$

```python
n = int(input())

res = 2
for i in range(1, n):
	res = res * i % 998244353

print(res)
```

- 对于 $ \textrm{Subtask 4} $：

考虑在 $ \textrm{Subtask 1} $ 的基础上进行二次扫描，使时间复杂度降低。

设 $ g\left(u\right) $ 为以 $ u $ 为根节点时，删去整棵树的方案数。

答案即为 $ \sum_{u = 1}^n g\left(u\right) $。

不难得出：

$$
\begin{aligned}
  	g\left(v\right) &= f\left(v\right) \times \frac{g\left(u\right)}{f\left(v\right) \times \begin{pmatrix} n - 1 \\ n - \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix}} \times \begin{pmatrix} n - 1 \\ \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix} \\
    	 			&= \frac{g\left(u\right) \times \begin{pmatrix} n - 1 \\ \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix}}{\begin{pmatrix} n - 1 \\ n - \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix}} \\
                    &= \frac{g\left(u\right) \times \operatorname{size}\left(v\right)}{n - \operatorname{size}\left(v\right)}
\end{aligned}
$$

其中 $ \operatorname{size}\left(v\right) \in [1, n - 1], n - \operatorname{size}\left(v\right) \in [1, n - 1] $。故我们只需在 $ \mathcal{O}\left(n\right) $ 的时间内递推求出 $ 1, 2, \dots, n $ 的逆元，上述转移就是 $ \mathcal{O}\left(1\right) $ 的。

上述转移同样进行 $ n - 1 $ 次，故整个程序的时间复杂度为 $ \mathcal{O}\left(n\right) $。

当然在转移的过程中直接求出逆元，带上一个 $ \log_2 998244353 $ 的常数也可以通过。

完整代码如下：

```cpp
#include <iostream>
#include <vector>

const int mod = 998244353;

std::vector<std::vector<int>> graph;
std::vector<int> inv, fact, fact_inv, dp, size;

void solve_1(const int cur, const int fa);
void solve_2(const int cur, const int fa);

int binpow(int a, int n);
void prework(const int n);
int C(const int n, const int m);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;
    graph = std::vector<std::vector<int>>(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        std::cin >> u >> v; --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    inv = fact = fact_inv = std::vector<int>(n + 1);
    prework(n);
    
    dp = size = std::vector<int>(n);
    solve_1(0, -1); solve_2(0, -1);

    int res = 0;
    for (const int i : dp)
        res = (res + i) % mod;

    std::cout << res << std::endl;

    return 0;
}

void solve_1(const int cur, const int fa) {
    size[cur] = 1, dp[cur] = 1;
    for (const int to : graph[cur]) {
        if (to == fa) continue;

        solve_1(to, cur);
        dp[cur] = (long long)dp[cur] * dp[to] % mod * C(size[cur] + size[to] - 1, size[cur] - 1) % mod;
        size[cur] += size[to];
    }
}

void solve_2(const int cur, const int fa) {
    for (const int to : graph[cur]) {
        if (to == fa) continue;

        dp[to] = (long long)dp[cur] * size[to] % mod * inv[size[0] - size[to]] % mod;
        solve_2(to, cur);
    }
}

int binpow(int a, int n) {
    int res = 1;
    for (; n; a = (long long)a * a % mod, n >>= 1)
        if (n & 1)
            res = (long long)res * a % mod;
    return res;
}

void prework(const int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) 
        inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;

    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (long long)fact[i - 1] * i % mod;
    
    fact_inv[n] = binpow(fact[n], mod - 2);
    for (int i = n - 1; i; --i)
        fact_inv[i] = (long long)fact_inv[i + 1] * (i + 1) % mod;
}

int C(const int n, const int m) {
    return (long long)fact[n] * fact_inv[m] % mod * fact_inv[n - m] % mod;
}
```

Python 中实现递归算法时，每一帧栈帧的占用空间较大，容易导致栈溢出，不能通过本题极端数据。

因此下面的 Python 标程将递归实现改为非递归实现。

```python
global MOD, graph, inv, fact, fact_inv, fa, order, size, dp

def get_fact(n: int) -> None:
    inv[1] = 1
    for i in range(2, n + 1):
        inv[i] = (MOD - MOD // i) * inv[MOD % i] % MOD

    fact[0] = 1
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    
    fact_inv[n] = pow(fact[n], MOD - 2, MOD)
    for i in range(n - 1, -1, -1):
        fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD

def C(n: int, m: int) -> int:
    return fact[n] * fact_inv[m] * fact_inv[n - m] % MOD

def bfs() -> None:
    order.append(0)
    for cur in order:
        for to in graph[cur]:
            if to == fa[cur]:
                continue
            fa[to] = cur
            order.append(to)

def solve_1() -> None:
    for u in reversed(order[1:]):
        v = fa[u]
        dp[v] = dp[v] * dp[u] * C(size[v] + size[u] - 1, size[v] - 1) % MOD
        size[v] += size[u]

def solve_2() -> None:
    for u in order:
        for v in graph[u]:
            if v == fa[u]:
                continue
            dp[v] = dp[u] * size[v] * inv[size[0] - size[v]] % MOD


if __name__ == "__main__":
    
    MOD = 998244353
    n = int(input())
    inv = [0] * (n + 1)
    fact = [0] * (n + 1)
    fact_inv = [0] * (n + 1)
    get_fact(n)

    graph = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = [int(i) for i in input().split()]
        u -= 1; v -= 1
        graph[u].append(v)
        graph[v].append(u)

    fa = [-1] * n; order = []
    bfs()

    size = [1] * n; dp = [1] * n
    solve_1(); solve_2()

    print(sum(dp) % MOD)
```
