#include <iostream>

int main() {
	std::string s;
	std::cin >> s;

	bool res = s.find("nnsz") != std::string::npos;
	std::cout << (res ? "yes\n" : "no\n");

	return 0;
}
