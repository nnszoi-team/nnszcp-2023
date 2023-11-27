#include "testlib.h"
#include <iostream>
#include <vector>

#include <cassert>
#include <iostream>

template <typename T, T _modulo> class ModInt {
  private:
	T _data;

  public:
	inline void fix() {
		if (_data < 0) _data += _modulo;
		if (_data >= _modulo) _data -= _modulo;
	}
	ModInt(T _data = 0) : _data(_data % _modulo) {}
	T data() const { return _data; }
	T modulo() const { return _modulo; }
	operator bool() const { return _data != 0; }
	operator T() const { return _data; }

	template <typename S> friend ModInt operator^(ModInt lhs, S rhs) {
		ModInt res(1);
		for (; rhs; rhs /= 2, lhs *= lhs)
			if (rhs % 2) res *= lhs;
		return res;
	}
	template <typename S> ModInt &operator^=(S exp) {
		ModInt res = *this ^ exp;
		return *this = res, *this;
	}

	ModInt operator~() {
		assert(_data != 0);
		return *this ^ (_modulo - 2);
	}
	ModInt &operator*=(ModInt rhs) {
		return _data = 1ll * _data * rhs._data % _modulo, *this;
	}
	ModInt &operator+=(ModInt rhs) { return _data += rhs.data(), fix(), *this; }
	ModInt &operator-=(ModInt rhs) { return _data -= rhs.data(), fix(), *this; }
	ModInt &operator/=(ModInt rhs) { return *this *= ~rhs, *this; }
	friend ModInt operator*(ModInt lhs, ModInt rhs) {
		ModInt res = lhs;
		res *= rhs;
		return res;
	}
	friend ModInt operator+(ModInt lhs, ModInt rhs) {
		ModInt res = lhs;
		res += rhs;
		return res;
	}
	friend ModInt operator-(ModInt lhs, ModInt rhs) {
		ModInt res = lhs;
		res -= rhs;
		return res;
	}
	friend ModInt operator/(ModInt lhs, ModInt rhs) {
		ModInt res = lhs;
		res /= rhs;
		return res;
	}
	template <typename S> ModInt &operator*=(S rhs) {
		return _data *= ModInt(T(rhs)), *this;
	}
	template <typename S> ModInt &operator+=(S rhs) {
		return _data += ModInt(T(rhs)), *this;
	}
	template <typename S> ModInt &operator-=(S rhs) {
		return _data -= ModInt(T(rhs)), *this;
	}
	template <typename S> ModInt &operator/=(S rhs) {
		return *this /= ModInt(T(rhs)), *this;
	}
	template <typename S> friend ModInt operator*(ModInt lhs, S rhs) {
		return lhs * ModInt(T(rhs));
	}
	template <typename S> friend ModInt operator+(ModInt lhs, S rhs) {
		return lhs + ModInt(T(rhs));
	}
	template <typename S> friend ModInt operator-(ModInt lhs, S rhs) {
		return lhs - ModInt(T(rhs));
	}
	template <typename S> friend ModInt operator/(ModInt lhs, S rhs) {
		return lhs / ModInt(T(rhs));
	}
	friend std::istream &operator>>(std::istream &is, ModInt &s) {
		return is >> s._data, s.fix(), is;
	}
	friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
		return os << x.data();
	}
	friend bool operator==(ModInt lhs, ModInt rhs) { return lhs.data() == rhs.data(); }
	friend bool operator!=(ModInt lhs, ModInt rhs) { return lhs.data() != rhs.data(); }
};

template <typename T> std::string to_string(T data) {
	std::string cur;
	if (data == 0) cur += "0";
	while (data) {
		cur += (char)((data % 10) + '0');
		data /= 10;
	}
	std::reverse(cur.begin(), cur.end());
	return cur;
}

template <typename T, T _modulo> class Point {
  public:
	ModInt<T, _modulo> x, y;
	Point(int x, int y) : x(x), y(y) {}
	Point(ModInt<T, _modulo> x, ModInt<T, _modulo> y) : x(x), y(y) {}

	bool operator==(const Point rhs) const { return rhs.x == x && rhs.y == y; }
};

template <typename T, T _modulo> class Vector {
  public:
	ModInt<T, _modulo> x, y;
	Vector(int x, int y) : x(x), y(y) {}
	Vector(Point<T, _modulo> lhs, Point<T, _modulo> rhs)
		: x(rhs.x - lhs.x), y(rhs.y - lhs.y) {}
	bool operator==(const Vector rhs) const { return rhs.x == x && rhs.y == y; }
};

template <typename T, T _modulo> class Line {
  public:
	Point<T, _modulo> p;
	Vector<T, _modulo> v;
	Line(Point<T, _modulo> p, Vector<T, _modulo> v) : p(p), v(v) {}
};

template <typename T, T _modulo> bool isZeroVector(const Vector<T, _modulo> &x) {
	return x.x == 0 && x.y == 0;
}

template <typename T, T _modulo>
bool isParrellelVector(const Vector<T, _modulo> &m, const Vector<T, _modulo> &n) {
	ouf.quitif(_wa, isZeroVector(m) || isZeroVector(n), "zero vector was found");
	if ((m.x == 0 && n.x == 0) || (m.y == 0 && n.y == 0)) return true;
	if (m.x == 0 || n.x == 0 || m.y == 0 || n.y == 0) return false;
	return m.x / m.y == n.x / n.y;
}

template <typename T, T _modulo>
Point<T, _modulo> operator^(Line<T, _modulo> s, Line<T, _modulo> t) {
	ouf.quitif(isParrellelVector(s.v, t.v), "parrellel lines found");
	auto A = m.p, B = n.p;
	auto a = m.v, b = n.v;
	auto temp = ((B.x - A.x) * b.y - (B.y - A.y) * b.x) / (a.x * b.y - a.y * b.x);
	return A + a * temp;
}

using i64 = long long;
const i64 Inf = 1'000'000'000;

std::vector<std::vector<int>> readAnswer() {
	int n;
	n = ouf.readInt(1, 1800, "n");
	std::vector<std::vector<int>> draw(n);

	for (int i = 0; i < n; ++i) {
		int op;
		op = ouf.readInt(1, 2, "op");
		if (op == 1) {
			i64 x, y;
			draw.emplace_back(Point<i64, 998244353>(x, y));
		} else {
			int s, t, u, v;
			s = ouf.readInt(1, i, "s") - 1;
			t = ouf.readInt(1, i, "t") - 1;
			u = ouf.readInt(1, i, "u") - 1;
			v = ouf.readInt(1, i, "v") - 1;
			Line<i64, 998244353> f(draw[s], draw[t]);
			auto g(draw[u], draw[v]);
			draw.emplace_back(f ^ g);
			ouf.quitif(!(draw.back().x >= F(0, 1) && draw.back().x <= F(p, 1) &&
						 draw.back().y >= F(0, 1) && draw.back().y <= F(p, 1)),
					   _wa,
					   "the point A_%d (%.8lf, %.8lf), or (%s, %s), is "
					   "not in the square area, which is from (0, 0) to "
					   "(%lld, %lld)",
					   i + 1, draw.back().x.real, draw.back().y.real,
					   draw.back().x.data().data(), draw.back().y.data().data(), p, p);
		}
	}
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	i64 p, a, b, c, d;
	p = inf.readInt(2, Inf, "p");
	a = inf.readInt(0, Inf, "a");
	b = inf.readInt(1, Inf, "b");
	c = inf.readInt(0, Inf, "c");
	d = inf.readInt(1, Inf, "d");

	std::vector<Point<i64, 998244353>> draw;
	for (int i = 0; i < n; ++i) {
		int op;
		op = ouf.readInt(1, 2, "op");
		if (op == 1) {
			i64 x, y;
			x = ouf.readInt(0, p, "x");
			y = ouf.readInt(0, p, "y");
			draw.emplace_back(Point<i64, 998244353>(x, y));
		} else {
			int s, t, u, v;
			s = ouf.readInt(1, i, "s") - 1;
			t = ouf.readInt(1, i, "t") - 1;
			u = ouf.readInt(1, i, "u") - 1;
			v = ouf.readInt(1, i, "v") - 1;
			Line<i64, 998244353> f(draw[s], draw[t]);
			auto g(draw[u], draw[v]);
			draw.emplace_back(f ^ g);
			ouf.quitif(!(draw.back().x >= F(0, 1) && draw.back().x <= F(p, 1) &&
						 draw.back().y >= F(0, 1) && draw.back().y <= F(p, 1)),
					   _wa,
					   "the point A_%d (%.8lf, %.8lf), or (%s, %s), is "
					   "not in the square area, which is from (0, 0) to "
					   "(%lld, %lld)",
					   i + 1, draw.back().x.real, draw.back().y.real,
					   draw.back().x.data().data(), draw.back().y.data().data(), p, p);
		}
	}

	P final_point(F(a, b), F(c, d));
	if (std::find(draw.begin(), draw.end(), final_point) != draw.end()) {
		quitf(_ok,
			  "the length of A is %d, the point A_%d is (%.8lf, %.8lf), or "
			  "(%s, %s), is equal "
			  "to the "
			  "target point",
			  n,
			  (int)(std::find(draw.begin(), draw.end(), final_point) - draw.begin() + 1),
			  final_point.x.real, final_point.y.real, final_point.x.data().data(),
			  final_point.y.data().data());
	} else {
		quitf(_wa,
			  "the point A_%d is (%.8lf, %.8lf), or (%s, %s), "
			  "is not equal "
			  "to the "
			  "target point (%.8lf, %.8lf), or (%s, %s)",
			  n, draw.back().x.real, draw.back().y.real, draw.back().x.data().data(),
			  draw.back().y.data().data(), final_point.x.real, final_point.y.real,
			  final_point.x.data().data(), final_point.y.data().data());
	}

	quitf(_fail, "checker error");
	return 0;
}
