#include <bits/stdc++.h>

#include "testlib.h"

using namespace std;
int n, s, sum, k;
int a[505][505];
bool bj[505];
bool f;
unordered_map<int, int> mp;

bool check() {
  int tmp;
  mp.clear();
  memset(bj, 0, sizeof bj);
  sum = 0;
  f = 1;
  for (int i = 1; i <= n; i++) {
    sum += a[i][1];
    for (int j = 1; j <= n; j++) {
      if (a[i][j] > k or a[i][j] < 0) {
        f = 0;
      }
      if (mp.find(a[i][j]) != mp.end()) {
        f = 0;
      }
      mp.insert({a[i][j], 0});
    }
  }
  if (!f) return 0;
  for (int j = 1; j < n; j++) {
    int cha = abs(a[1][1] - a[1][j + 1]);
    sum += cha;
    for (int i = 2; i <= n; i++) {
      if (abs(a[i][1] - a[i][j + 1]) != cha) return 0;
    }
  }

  if (sum != k) return 0;
  return 1;
}

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  int T = inf.readInt();

  int cnt = 0;
  while (T--) {
    n = inf.readInt(), k = inf.readInt();
    if (k < ((n - 1) * n * (n + 1) >> 1)) {
      int tmp = ouf.readInt();
      if (tmp == -1)
        continue;
      else {
        quitf(_wa, "The answer is wrong.");
        break;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = ouf.readInt();
      }
    }
    if (!check()) {
      quitf(_wa, "The answer is wrong.");
      break;
    }
  }
  quitf(_ok, "The answer is correct.");
  return 0;
}
