#include "testlib.h"
#include <vector>
#include <unordered_set>

namespace distinct {

void valid(const std::vector<int> &a, const int n) {
  std::unordered_set<int> set;
  for (int i = 0; i < n; ++i) set.insert(a[i]);

  if (set.size() != n) quitf(_fail, "Found repeated elements in a.");
}

}  // namespace distinct

namespace indistinct {

void valid(const std::vector<int> &a, const int n) {
  std::unordered_set<int> set;
  for (int i = 0; i < n; ++i) set.insert(a[i]);

  if (set.size() == n) quitf(_fail, "Elements in a are distinct.");
}

}  // namespace indistinct

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int is_distinct = atoi(argv[0]);

  int l = 1, r = 1e9;
  int n = inf.readInt(1, 200000, "n");
  inf.readEoln();

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = inf.readInt(l, r, "a[i]");
    inf.readSpace();
  }
  inf.readEoln();
  inf.readEof();

  if (is_distinct)
    distinct::valid(a, n);
  else
    indistinct::valid(a, n);

  return 0;
}
