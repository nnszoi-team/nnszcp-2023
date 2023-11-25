#include <unordered_set>
#include <vector>

#include "testlib.h"

namespace distinct {

void valid(const std::vector<int> &a, const int n) {
  std::unordered_set<int> set;
  for (int i = 0; i < n; ++i) set.insert(a[i]);

  if (set.size() != n) quitf(_fail, "Found repeated elements in a.");
}

}  // namespace distinct

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int is_distinct = atoi(argv[0]);

  int l = 1, r = 1e9;
  int n = inf.readInt(1, 200000, "n");
  inf.readEoln();

  std::vector<int> a(n);
  for (int i = 0; i + 1 < n; ++i) {
    a[i] = inf.readInt(l, r, "a[i]");
    inf.readSpace();
  }
  a[n - 1] = inf.readInt(l, r, "a[i]");
  inf.readEoln();
  inf.readEof();

  if (is_distinct)
    distinct::valid(a, n);

  return 0;
}
