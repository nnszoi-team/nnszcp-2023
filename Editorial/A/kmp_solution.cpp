#include <iostream>
#include <vector>

int main() {
    
    std::string s;
    std::cin >> s;
    s = "nnsz" + s;

    std::string ans = "no\n";
    std::vector<int> fail = { 0 };
    for (int i = 1; i < (int)s.size(); ++i) {
        int j = fail[i - 1];
        while (j && s[i] != s[j])
            j = fail[j - 1];
        j += s[i] == s[j];
        
        if (j >= 4) {
            ans = "yes\n";
            break;
        }
        fail.push_back(j);
    }

    std::cout << ans;

    return 0;
}
