#include <iostream>
#include <vector>

int main() {

    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    for (int& i : a) std::cin >> i;

    int max = a[0], diff = -2e9;
    for (int i = 1; i < n + 1; ++i) {
        diff = std::max(diff, a[i] - a[i - 1]);
        max = std::max(max, a[i]);
    }

    std::cout << max << '\n' << diff << '\n';

    return 0;
}
