- 对于 $ \textrm{Subtask 0} $：

暴力搜索，代码如下：

```cpp
#include <iostream>

const int max_n = 2e5 + 10;

struct Edge
{
	int next, to;
};

int head[max_n];
Edge edge[max_n << 1];
int edge_idx = 1;

int node_num;
int degree[max_n];
bool used[max_n << 1];

int ans = 0;

void add_edge(const int from, const int to);
void dfs(const int cnt_node);

int main()
{
	std::cin >> node_num;
	for (int i = 1; i <= node_num - 1; ++i)
	{
		int from, to;
		std::cin >> from >> to;
		add_edge(from, to);
		add_edge(to, from);
		++degree[from], ++degree[to];
	}

	dfs(1);
	
	std::cout << ans << '\n';
}

void add_edge(const int from, const int to)
{
	edge[++edge_idx].to = to;
	edge[edge_idx].next = head[from];
	head[from] = edge_idx;
}

void dfs(const int cnt_node)
{
	if (cnt_node >= node_num)
	{
		++ans;
		return;
	}

	for (int from = 1; from <= node_num; ++from)
	{
		if (degree[from] != 1)
			continue;
		for (int i = head[from]; i; i = edge[i].next)
		{
			if (used[i])
				continue;
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
void solve(const int cur, const int fa)
{
    size[cur] = 1;
    dp[cur] = 1;
    for (int i = head[cur]; i; i = edge[i].next)
	{
        int to = edge[i].to;
        if (to == fa)
            continue;

        solve(to, cur);
        dp[cur] = (long long)dp[cur] * dp[to] % mod * C(size[cur] + size[to] - 1, size[cur] - 1) % mod;
        size[cur] += size[to];
    }
}
```

在 `main()` 函数中：

```cpp
int res = 0;
for (int i = 1; i <= n; ++i)
{
	solve(i, 0);
	res = (res + dp[i]) % mod;
}

std::cout << res << std::endl;
```

- 对于 $ \textrm{Subtask 2} $：

由于整棵树是一条链，在删除前 $ n - 1 $ 个结点时，树上都恰好有 $ 2 $ 个叶子结点，故答案为 $ 2^{n - 1} $。

```python
n = int(input())
print(pow(2, n - 1, 998244353))
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

不难得出：

$$
\begin{aligned}
  	g\left(v\right) &= f\left(v\right) \times \frac{g\left(u\right)}{f\left(v\right) \times \begin{pmatrix} n - 1 \\ n - \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix}} \times \begin{pmatrix} n - 1 \\ \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix} \\
    	 			&= \frac{g\left(u\right) \times \begin{pmatrix} n - 1 \\ \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix}}{\begin{pmatrix} n - 1 \\ n - \operatorname{size}\left(v\right) - 1 \\ \end{pmatrix}}
\end{aligned}
$$

上述更新过程的时间复杂度同样是 $ \mathcal{O} \left(n\right) $ 的（将做除法（求逆元）的时间复杂度视为常数），故程序的总时间复杂度为 $ \mathcal{O} \left(n\right) $。

完整代码如下：

```cpp
#include <iostream>

const int mod = 998244353;
const int max_n = 2e5 + 10;

struct Edge
{
    int next, to;
};

int head[max_n];
Edge edge[max_n << 1];
int edge_idx = 0;

int fact[max_n << 1], fact_inv[max_n << 1];
int size[max_n];
int dp[max_n];

void add_edge(const int from, const int to);
void solve_1(const int cur, const int fa);
void solve_2(const int cur, const int fa);

int binpow(int a, int n);
int inv(const int a);
void get_fact(const int n);
int C(const int n, const int m);

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n - 1; ++i)
	{
        int from, to;
        std::cin >> from >> to;
        add_edge(from, to);
        add_edge(to, from);
    }

    get_fact(n);
    solve_1(1, 0);
    solve_2(1, 0);

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + dp[i]) % mod;

    std::cout << res << std::endl;

    return 0;
}

void add_edge(const int from, const int to)
{
    edge[++edge_idx].to = to;
    edge[edge_idx].next = head[from];
    head[from] = edge_idx;
}

void solve_1(const int cur, const int fa)
{
    size[cur] = 1;
    dp[cur] = 1;
    for (int i = head[cur]; i; i = edge[i].next)
	{
        int to = edge[i].to;
        if (to == fa)
            continue;

        solve_1(to, cur);
        dp[cur] = (long long)dp[cur] * dp[to] % mod * C(size[cur] + size[to] - 1, size[cur] - 1) % mod;
        size[cur] += size[to];
    }
}

void solve_2(const int cur, const int fa)
{
    for (int i = head[cur]; i; i = edge[i].next)
	{
        int to = edge[i].to;
        if (to == fa)
            continue;

        dp[to] = (long long)dp[cur] * C(size[1] - 1, size[to] - 1) % mod * inv(C(size[1] - 1, size[1] - size[to] - 1)) % mod;
        solve_2(to, cur);
    }
}

int binpow(int a, int n)
{
    int res = 1;
    for (; n; a = (long long)a * a % mod, n >>= 1)
        if (n & 1)
            res = (long long)res * a % mod;
    return res;
}

int inv(const int a)
{
    return binpow(a, mod - 2);
}

void get_fact(const int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n << 1; ++i)
        fact[i] = (long long)fact[i - 1] * i % mod;
	
	fact_inv[n << 1] = inv(fact[n << 1]);
	for (int i = (n << 1) - 1; i >= 0; --i)
		fact_inv[i] = (long long)fact_inv[i + 1] * (i + 1) % mod;
}

int C(const int n, const int m)
{
    if (m > n)
        return 0;
    return (long long)fact[n] * fact_inv[m] % mod * fact_inv[n - m] % mod;
}
```

Python 中实现递归算法时，每一帧栈帧的占用空间较大，容易导致栈溢出，不能通过本题极端数据。

因此下面的 Python 标程将递归实现改为非递归实现。

```python
global MOD, graph, fact, fact_inv, fa, order, size, dp

def inv(a: int) -> int:
    return pow(a, MOD - 2, MOD)

def get_fact(n: int) -> None:

    fact[0] = 1
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    
    fact_inv[n] = inv(fact[n])
    for i in range(n - 1, -1, -1):
        fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD

def C(n: int, m: int) -> int:
    return fact[n] * fact_inv[m] * fact_inv[n - m] % MOD

def bfs(n: int) -> None:

    tail = 1
    order[tail] = 1

    for i in range(1, n + 1):
        cur = order[i]
        for to in graph[cur]:
            if to == fa[cur]:
                continue
            fa[to] = cur
            tail += 1
            order[tail] = to

def solve_1(n: int) -> None:

    for i in range(n, 1, -1):
        u = order[i]
        v = fa[u]

        dp[v] = dp[v] * dp[u] * C(size[v] + size[u] - 1, size[v] - 1) % MOD
        size[v] += size[u]

def solve_2(n: int) -> None:

    for i in range(1, n + 1):
        u = order[i]
        for v in graph[u]:
            if v == fa[u]:
                continue
            dp[v] = dp[u] * C(size[1] - 1, size[v] - 1) * inv(C(size[1] - 1, size[1] - size[v] - 1)) % MOD


if __name__ == "__main__":
    
    n = int(input())
    MOD = 998244353
    fact = [ 0 for i in range(n + 1) ]
    fact_inv = [ 0 for i in range(n + 1) ]
    get_fact(n)

    graph = [ [] for i in range(n + 1) ]
    for i in range(n - 1):
        u, v = [ int(i) for i in input().split() ]
        graph[u].append(v)
        graph[v].append(u)

    fa = [ 0 for i in range(n + 1) ]
    order = [ 0 for i in range(n + 1) ]
    bfs(n)

    size = [ 1 for i in range(n + 1) ]
    dp = [ 1 for i in range(n + 1) ]
    dp[0] = size[0] = 0
    solve_1(n)
    solve_2(n)

    print(sum(dp) % MOD)
```