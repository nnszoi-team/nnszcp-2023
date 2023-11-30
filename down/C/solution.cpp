#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n, m;
    std::cin >> n >> m;

    std::vector <int> h(n), dh;
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
        for (int j = 0; j < i; ++j)
            dh.push_back(std::abs(h[i] - h[j]));
    }
    
    std::sort(dh.begin(), dh.end());

    while (m--) {
        int s;
        std::cin >> s;
        
        int res = std::upper_bound(dh.begin(), dh.end(), s) - dh.begin();
        std::cout << res << std::endl;
    }

    return 0;
}
