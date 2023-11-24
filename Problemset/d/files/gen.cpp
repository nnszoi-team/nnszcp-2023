#include <iostream>
#include <cstdlib>

int main() {
	
	const int T = 20;
	for (int i = 1; i <= T; ++i) {
		std::string idx = std::to_string(i);
		std::string cmd = "python gen.py > " + idx + ".in";
		system(cmd.c_str());
		cmd = "solution.exe < " + idx + ".in > " + idx + ".out";
		system(cmd.c_str());
	}
	
	return 0;
}

