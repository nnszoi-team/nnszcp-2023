#include "testlib.h"

#include <iostream>
#include <vector>

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

template <typename T> T gcd(const T a, const T b) { return b ? gcd(b, a % b) : a; }
template <typename T> T lcm(const T a, const T b) { return a / gcd(a, b) * b; }
template <typename T> class Fraction {
  protected:
	void simplify() {
		if (this->up * this->down < 0) {
			this->sign = -1;
		} else if (this->up == 0 || this->down == 0) {
			this->sign = 0;
		} else {
			this->sign = 1;
		}

		if (this->up < 0) {
			this->up = -this->up;
		}
		if (this->down < 0) {
			this->down = -this->down;
		}

		T g = gcd(this->up, this->down);
		this->up /= g, this->down /= g;
		this->real = (double)this->up / this->down * sign;
	}

  public:
	int sign;
	T up, down;
	double real;
	Fraction() : up(0), down(1), real(0) { simplify(); }
	Fraction(const T up, const T down) : up(up), down(down), real((double)up / down) {
		simplify();
	}

	std::string data() {
		std::string _sign;
		if (sign == 1)
			_sign += "+";
		else if (sign == -1)
			_sign += "-";
		auto _up = to_string(up);
		_up += "/";
		auto _down = to_string(down);
		_sign += _up;
		_sign += _down;
		return _sign;
	}

	double value() const { return this->real; }

	friend std::ostream &operator<<(std::ostream &os, Fraction f) {
		os << f.data();
		return os;
	}

	friend bool operator<(Fraction a, Fraction b) {
		return a.sign * a.up * b.down < b.sign * b.up * a.down;
	}
	friend bool operator>(Fraction a, Fraction b) {
		return a.up * b.down > b.up * a.down;
	}
	friend bool operator==(Fraction a, Fraction b) { return !(a < b || a > b); }
	friend bool operator<=(Fraction a, Fraction b) { return a < b || a == b; }
	friend bool operator>=(Fraction a, Fraction b) { return a > b || a == b; }
	friend bool operator!=(Fraction a, Fraction b) { return !(a == b); }
	friend Fraction operator+(const Fraction &a, const Fraction &b) {
		T l = lcm(a.down, b.down);
		Fraction res(a.up * (l / a.down) * a.sign + b.up * (l / b.down) * b.sign, l);
		return res;
	}
	Fraction &operator+=(const Fraction &other) {
		*this = *this + other;
		return *this;
	}
	friend Fraction operator-(const Fraction &a, const Fraction &b) {
		T l = lcm(a.down, b.down);
		Fraction res(a.up * (l / a.down) * a.sign - b.up * (l / b.down) * b.sign, l);
		return res;
	}
	Fraction &operator-=(const Fraction &other) {
		*this = *this - other;
		return *this;
	}
	friend Fraction operator*(const Fraction &a, const Fraction &b) {
		return Fraction(a.up * b.up * a.sign * b.sign, a.down * b.down);
	}
	Fraction &operator*=(const Fraction &other) {
		*this = (*this) * other;
		return *this;
	}
	Fraction inv() const { return Fraction(this->down * this->sign, this->up); }
	friend Fraction inv(const Fraction &f) { return f.inv(); }
	friend Fraction operator/(const Fraction &a, const Fraction &b) {
		return a * b.inv();
	}
	Fraction &operator/=(const Fraction &other) {
		*this = (*this) / other;
		return *this;
	}
};

template <typename T> class Point {
  public:
	Fraction<T> x, y;
	Point(Fraction<T> x, Fraction<T> y) : x(x), y(y) {}
};
template <typename T> bool operator==(Point<T> A, Point<T> B) {
	return A.x == B.x && A.y == B.y;
}
template <typename T> class Line {
  public:
	Fraction<T> a, b, c;
	Line(Point<T> A, Point<T> B) : a(A.y - B.y), b(B.x - A.x), c(B.y * A.x - B.x * A.y) {}
};

template <typename T> Point<T> operator^(Line<T> s, Line<T> t) {
	ouf.quitif(s.a * t.b - s.b * t.a == Fraction<T>(0, 1), _wa,
			   "the two lines %.8lfx + %.8lfy + %.8lf = 0 and %.8lfx + %.8lfy "
			   "+ %.8lf = 0 or "
			   "%sx + %sy + %s = 0 and %sx + %sy + %s = 0, are "
			   "parallel or equal",
			   s.a.real, s.b.real, s.c.real, t.a.real, t.b.real, t.c.real,
			   s.a.data().data(), s.b.data().data(), s.c.data().data(), t.a.data().data(),
			   t.b.data().data(), t.c.data().data());
	Point<T> cur(Fraction<T>((s.b * t.c - s.c * t.b) / (s.a * t.b - s.b * t.a)),
				 Fraction<T>((s.a * t.c - s.c * t.a) / (s.b * t.a - s.a * t.b)));
	return cur;
}

using i64 = long long;
using i128 = __int128_t;
using F = Fraction<i128>;
using P = Point<i128>;
using L = Line<i128>;
const i64 Inf = 1'000'000'000;

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	i64 p, a, b, c, d;
	p = inf.readInt(2, Inf, "p");
	a = inf.readInt(0, Inf, "a");
	b = inf.readInt(1, Inf, "b");
	c = inf.readInt(0, Inf, "c");
	d = inf.readInt(1, Inf, "d");

	int n;
	n = ouf.readInt(1, 1800, "n");
	std::vector<P> draw;
	for (int i = 0; i < n; ++i) {
		int op;
		op = ouf.readInt(1, 2, "op");
		if (op == 1) {
			i64 x, y;
			x = ouf.readInt(0, p, "x");
			y = ouf.readInt(0, p, "y");
			draw.emplace_back(F(x, 1), F(y, 1));
		} else {
			int s, t, u, v;
			s = ouf.readInt(1, i, "s") - 1;
			t = ouf.readInt(1, i, "t") - 1;
			u = ouf.readInt(1, i, "u") - 1;
			v = ouf.readInt(1, i, "v") - 1;
			L f(draw[s], draw[t]);
			L g(draw[u], draw[v]);
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
