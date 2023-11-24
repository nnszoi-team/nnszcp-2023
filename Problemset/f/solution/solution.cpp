#include <iostream>
#include <cmath>

void solve() {
    
    double a, b; std::cin >> a >> b;
    
    double k = a / b;
    double ans = std::max(pow(k, 2) + 1, pow(pow(k, 2) * 0.25 + 1, 2));

    std::cout << std::fixed << ans << '\n';
}

int main() {
    
    int T; std::cin >> T;
    while (T--) solve();

    return 0;
}
