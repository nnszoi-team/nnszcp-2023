#include "testlib.h"
#include <vector>
#include <unordered_set>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    
	int T = inf.readInt();
    while (T--) {
        int n = inf.readInt(), k = inf.readInt();
        if (k < (n - 1) * n * (n + 1) / 2) {
            int tmp = ouf.readInt();
            if (tmp == -1)
                continue;
            else {
                quitf(_wa, "Answer matrix found when there is no solution.");
                break;
            }
        }

		std::vector<std::vector<int>> a(n, std::vector<int>(n));
		std::unordered_set<int> set;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = ouf.readInt();
				
				if (a[i][j] < 0 || k < a[i][j])
					quitf(_wa, "Element in the answer matrix out of range.");
				
				if (set.count(a[i][j]))
					quitf(_wa, "Repeated element found in the answer matrix.");
				set.insert(a[i][j]);
			}
		}
		set.clear();

		long long sum = 0;
		for (int i = 0; i < n; ++i)
			sum += a[i][0];
		
		for (int j = 0; j < n - 1; ++j) {
			long long diff = a[0][j + 1] - a[0][j];
			sum += (n - j - 1) * diff;
			for (int i = 1; i < n; ++i) {
				if (a[i][j + 1] - a[i][j] != diff)
					quitf(_wa, "There is a way to choose elements from the answer matrix such that the sum of the elements does not equal to k.");
			}
		}
		if (sum != k)
			quitf(_wa, "There is a way to choose elements from the answer matrix such that the sum of the elements does not equal to k.");
    }
    quitf(_ok, "The answer is correct.");

    return 0;
}
