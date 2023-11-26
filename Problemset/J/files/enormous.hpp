#include <iostream>
#include <vector>

template <typename T, size_t BitLen> class Enormous {
	short sign;
	size_t length;
	std::vector<T> data;
	friend Enormous &operator+=(Enormous x) {
		for (size_t i = 0; i < length && i < x.length; ++i) {
			data[i] += x.data[i];
		}
		T res = 0;
		for (size_t i = 0; i < length; ++i) {
			data[i] += res;
			if (data[i] >= (1 << BitLen)) {
				res = data[i] - (1 << BitLen) + 1;
			}
		}
		if (res) data.push_back(res);
	}

	friend Enormous &operator-=(Enormous x) {
		for (size_t i = 0; i < length && i < x.length; ++i) {
			data[i] -= x.data[i];
		}
		T res = 0;
		for (size_t i = 0; i < length; ++i) {
			data[i] += res;
			if (data[i] >= (1 << BitLen)) {
				res = data[i] - (1 << BitLen) + 1;
			}
		}
		if (res) data.push_back(res);
	}
};
