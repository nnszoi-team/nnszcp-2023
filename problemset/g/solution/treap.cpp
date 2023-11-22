#include <cstdlib>
#include <iostream>
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

  void zig(int& father);
  void zag(int& father);
  void insert(const int value, int& cur);

  int query(const int value, const int cur);
};

int a[max_n];
Treap treap;

int main() {
  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);

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

void Treap::zig(int& father) {
  int child = node[father].lc;

  node[father].lc = node[child].rc;
  node[child].rc = father;

  father = child;

  update(node[father].rc);
  update(father);
}

void Treap::zag(int& father) {
  int child = node[father].rc;

  node[father].rc = node[child].lc;
  node[child].lc = father;

  father = child;

  update(node[father].lc);
  update(father);
}

void Treap::insert(const int value, int& cur) {
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
  } else {
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
