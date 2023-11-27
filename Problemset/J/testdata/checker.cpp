#include "testlib.h"

#include <cassert>
#include <cmath>

#include <iostream>
#include <vector>

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

const int LIMIT_OF_N = 1500;
const int INF = 10'000'000;

const char ACCEPTED_MSG[] = "wonderful answer";
const char WRONG_ANSWER_MSG[] = "where is the target huh";

const char ZERO_VECTOR_MSG[] = "oops zero vector found";
const char PARRELLEL_LINES_MSG[] = "oops parrellel lines do not intersect";
const char OUT_OF_RANGE_MSG[] = "oops point is out of range";

std::vector<std::pair<bool, std::vector<int>>> readAnswerSequence(const int &p) {
	int n = ouf.readInt(1, LIMIT_OF_N, "n");
	std::vector<std::pair<bool, std::vector<int>>> sequence(n);
	for (int i = 0; i < n; ++i) {
		int op = ouf.readInt(1, 2, "op");
		if (op == 1) {
			int x = ouf.readInt(0, p, "x");
			int y = ouf.readInt(0, p, "y");
			std::vector<int> argument = {x, y};
			sequence[i] = {false, argument};
		} else {
			int s = ouf.readInt(1, i, "s");
			int t = ouf.readInt(1, i, "t");
			int u = ouf.readInt(1, i, "u");
			int v = ouf.readInt(1, i, "v");
			--s, --t, --u, --v;
			ouf.quitif(s == t, _wa, ZERO_VECTOR_MSG);
			ouf.quitif(u == v, _wa, ZERO_VECTOR_MSG);
			std::vector<int> argument = {s, t, u, v};
			sequence[i] = {true, argument};
		}
	}
	return sequence;
}

using i64 = long long;

template <typename T> struct Point {
	T x, y;
	Point(const T x = T(), const T y = T()) : x(x), y(y) {}
	friend std::ostream &operator<<(std::ostream &out, const Point &P) {
		out << "(" << P.x << ", " << P.y << ")";
		return out;
	}
};

template <typename T> struct Vector {
  public:
	T x, y;
	Vector(const T x = T(), const T y = T()) : x(x), y(y) {}
	friend std::ostream &operator<<(std::ostream &out, const Vector &P) {
		out << "(" << P.x << ", " << P.y << ")";
		return out;
	}
};

template <typename T> Vector<T> operator-(const Point<T> &A, const Point<T> &B) {
	return Vector<T>(A.x - B.x, A.y - B.y);
}
template <typename T> Point<T> operator+(const Point<T> &A, const Vector<T> &v) {
	return Point<T>(A.x + v.x, A.y + v.y);
}
template <typename T> Vector<T> operator*(const Vector<T> &v, const T &k) {
	return Vector<T>(v.x * k, v.y * k);
}
template <typename T> bool operator==(const Point<T> &A, const Point<T> &B) {
	return A.x == B.x && A.y == B.y;
}
template <typename T> bool operator==(const Vector<T> &A, const Vector<T> &B) {
	return A.x == B.x && A.y == B.y;
}

template <typename T> class Line {
  public:
	Point<T> point;
	Vector<T> vector;
	Line(const Point<T> &point = Point<T>(), const Vector<T> &vector = Vector<T>())
		: point(point), vector(vector) {}
	Line(const Point<T> &A = Point<T>(), const Point<T> &B = Point<T>()) {
		ouf.quitif(A == B, _wa, ZERO_VECTOR_MSG);
		point = A, vector = B - A;
	}
};
template <typename T> bool isZero(const Vector<T> &v) {
	return v.x == T(0) && v.y == T(0);
}
template <typename T> bool isParrellel(const Vector<T> &m, const Vector<T> &n) {
	ouf.quitif(isZero(m) || isZero(n), _wa, ZERO_VECTOR_MSG);
	if ((m.x == T(0) && n.x == T(0)) || (m.y == T(0) && n.y == T(0))) return true;
	if (m.x == T(0) || n.x == T(0) || m.y == T(0) || n.y == T(0)) return false;
	return m.x / m.y == n.x / n.y;
}

template <typename T> Point<T> operator^(const Line<T> &m, const Line<T> &n) {
	ouf.quitif(isParrellel(m.vector, n.vector), _wa, PARRELLEL_LINES_MSG);
	Point<T> A = m.point, B = n.point;
	Vector<T> a = m.vector, b = n.vector;
	T temp = ((B.x - A.x) * b.y - (B.y - A.y) * b.x) / (a.x * b.y - a.y * b.x);
	return A + a * temp;
}

template <typename T> bool isValid(const Point<T> &P, const int &p) {
	return ((std::isnormal(P.x) || P.x == T(0)) && (std::isnormal(P.y) || P.y == T(0))) &&
		   (P.x <= T(p) && P.x >= T(0)) && (P.y <= T(p) && P.y >= T(0));
}

template <typename T>
bool checkDouble(const std::vector<std::pair<bool, std::vector<int>>> &sequence,
				 const int &p, const int &a, const int &b, const int &c, const int &d) {
	std::vector<Point<T>> list;
	for (auto [option, argument] : sequence) {
		if (option == false) {
			list.emplace_back(argument[0], argument[1]);
		} else {
			Line<T> f(list[argument[0]], list[argument[1]]);
			Line<T> g(list[argument[2]], list[argument[3]]);
			list.push_back(f ^ g);
		}
		ouf.quitif(isValid(list.back(), p) == false, _wa, OUT_OF_RANGE_MSG);
	}
	return true;
}

template <typename T>
bool checkModulo(const std::vector<std::pair<bool, std::vector<int>>> &sequence,
				 const int &p, const int &a, const int &b, const int &c, const int &d) {
	std::vector<Point<T>> list;
	for (auto [option, argument] : sequence) {
		if (option == false) {
			list.emplace_back(argument[0], argument[1]);
		} else {
			Line<T> f(list[argument[0]], list[argument[1]]);
			Line<T> g(list[argument[2]], list[argument[3]]);
			list.push_back(f ^ g);
		}
	}
	T x = (T)a / (T)b;
	T y = (T)c / (T)d;
	Point<T> F(x, y);
	return std::find(list.begin(), list.end(), F) != list.end();
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	int p = inf.readInt(2, INF, "p");
	int a = inf.readInt(1, INF, "a");
	int b = inf.readInt(a, INF, "b");
	int c = inf.readInt(1, INF, "c");
	int d = inf.readInt(c, INF, "d");

	auto sequence = readAnswerSequence(p);

	bool ok = checkDouble<long double>(sequence, p, a, b, c, d);

	ok &= checkModulo<ModInt<int, 13'533'511>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 19'260'817>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 27'644'437>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 57'885'161>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 86'538'889>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 111'181'111>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 305'175'781>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 370'248'451>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 479'001'599>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 998'244'353>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 998'244'853>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'007>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'009>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'021>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'321>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'663>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'801>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'861>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'871>>(sequence, p, a, b, c, d);
	ok &= checkModulo<ModInt<int, 1'000'000'993>>(sequence, p, a, b, c, d);

	if (ok) {
		quitf(_ok, ACCEPTED_MSG);
	} else {
		quitf(_wa, WRONG_ANSWER_MSG);
	}

	return 0;
}
