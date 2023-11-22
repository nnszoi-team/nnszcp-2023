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
