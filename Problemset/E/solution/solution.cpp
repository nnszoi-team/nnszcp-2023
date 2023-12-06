#include <iostream>

void solve() {

    int n, k;
    std::cin >> n >> k;
    
    int k_min = (n - 1) * n * (n + 1) / 2;
    if (k < k_min) {
        std::cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << i * n + j + (i == n - 1 ? k - k_min : 0) << ' ';
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) solve();

    return 0;
}
