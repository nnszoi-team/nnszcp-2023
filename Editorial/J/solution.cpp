#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
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

template <typename T> T gcd(const T a, const T b) {
	return b ? gcd(b, a % b) : a;
}
template <typename T> T lcm(const T a, const T b) {
	return a / gcd(a, b) * b;
}

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
		this->real = (double)this->up / this->down * this->sign;
	}

  public:
	int sign;
	T up, down;
	double real;

	Fraction() : up(0), down(1), real(0) {
		simplify();
	}
	Fraction(const T up, const T down) : up(up), down(down), real((double)up / down) {
		simplify();
	}

	std::string data() const {
		std::string _sign = this->sign == 1 ? "+" : this->sign == -1 ? "-" : "";		
		std::string _up = to_string(this->up);
		std::string _down = to_string(this->down);
		return _sign + _up + "/" + _down;
	}

	double value() const {
		return this->real;
	}
	friend std::ostream &operator<<(std::ostream &os, const Fraction &f) {
		os << f.data();
		return os;
	}
	friend bool operator<(const Fraction &a, const Fraction &b) {
		return a.sign * a.up * b.down < b.sign * b.up * a.down;
	}
	friend bool operator>(const Fraction &a, const Fraction &b) {
		return a.up * b.down > b.up * a.down;
	}
	friend bool operator==(const Fraction &a, const Fraction &b) {
		return !(a < b || a > b);
	}
	friend bool operator<=(const Fraction &a, const Fraction &b) {
		return a < b || a == b;
	}
	friend bool operator>=(const Fraction &a, const Fraction &b) {
		return a > b || a == b;
	}
	friend bool operator!=(const Fraction &a, const Fraction &b) {
		return !(a == b);
	}
	friend Fraction operator+(const Fraction &a, const Fraction &b) {
		T l = lcm(a.down, b.down);
		Fraction res(a.up * (l / a.down) * a.sign + b.up * (l / b.down) * b.sign, l);
		return res;
	}
	Fraction &operator+=(const Fraction &other) {
		return *this = *this + other;
	}
	friend Fraction operator-(const Fraction &a, const Fraction &b) {
		T l = lcm(a.down, b.down);
		Fraction res(a.up * (l / a.down) * a.sign - b.up * (l / b.down) * b.sign, l);
		return res;
	}
	Fraction &operator-=(const Fraction &other) {
		return *this = *this - other;
	}
	friend Fraction operator*(const Fraction &a, const Fraction &b) {
		return Fraction(a.up * b.up * a.sign * b.sign, a.down * b.down);
	}
	Fraction &operator*=(const Fraction &other) {
		return *this = (*this) * other;
	}
	Fraction inv() const {
		return Fraction(this->down * this->sign, this->up);
	}
	friend Fraction inv(const Fraction &f) {
		return f.inv();
	}
	friend Fraction operator/(const Fraction &a, const Fraction &b) {
		return a * b.inv();
	}
	Fraction &operator/=(const Fraction &other) {
		return *this = (*this) / other;
	}
};

template <typename T> class Point {
  public:
	Fraction<T> x, y;
	Point(Fraction<T> x, Fraction<T> y) : x(x), y(y) {}
	Point() {}
};
template <typename T> bool operator<(Point<T> A, Point<T> B) {
	if (A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}
template <typename T> bool operator==(Point<T> A, Point<T> B) {
	return A.x == B.x && A.y == B.y;
}
template <typename T> class Line {
  public:
	Fraction<T> a, b, c;
	Line(Point<T> A, Point<T> B) : a(A.y - B.y), b(B.x - A.x), c(B.y * A.x - B.x * A.y) {}
};

template <typename T> Point<T> operator^(Line<T> s, Line<T> t) {
	Point<T> cur(Fraction<T>((s.b * t.c - s.c * t.b) / (s.a * t.b - s.b * t.a)),
				 Fraction<T>((s.a * t.c - s.c * t.a) / (s.b * t.a - s.a * t.b)));
	return cur;
}

using i64 = long long;
using i128 = __int128_t;
using F = Fraction<i128>;
using P = Point<i128>;
using L = Line<i128>;

int main() {
	int p, a, b, c, d;
	std::cin >> p >> a >> b >> c >> d;

	std::vector<std::vector<int>> answer;
	std::vector<P> ref;
	std::map<P, int> list;

	auto draw_op1 = [&](int x, int y) {
		if (list.count(P(F(x, 1), F(y, 1)))) return P(F(x, 1), F(y, 1));
		int id = answer.size();
		answer.push_back({1, x, y});
		list.emplace(P(F(x, 1), F(y, 1)), id);
		ref.emplace_back(F(x, 1), F(y, 1));
		return P(F(x, 1), F(y, 1));
	};

	auto draw_op2 = [&](int s, int t, int u, int v) {
		if (list.count(L(ref[s], ref[t]) ^ L(ref[u], ref[v])))
			return L(ref[s], ref[t]) ^ L(ref[u], ref[v]);
		int id = answer.size();
		answer.push_back({2, s + 1, t + 1, u + 1, v + 1});
		list.emplace((L(ref[s], ref[t]) ^ L(ref[u], ref[v])), id);
		ref.emplace_back(L(ref[s], ref[t]) ^ L(ref[u], ref[v]));
		return ref.back();
	};

	auto parrallel_y_grid_binary_line = [&](int x, int bound, int L, int R) {
		F l = F(L, 1), r = F(R, 1);
		P ul(F(L, 1), F(2, 1)), ur(F(R, 1), F(2, 1)), dl(F(L, 1), F(0, 1)),
			dr(F(R, 1), F(0, 1)), ml(F(L, 1), F(1, 1)), mr(F(R, 1), F(1, 1));
		draw_op1(L, 2), draw_op1(R, 2), draw_op1(L, 0), draw_op1(R, 0), draw_op1(L, 1),
			draw_op1(R, 1);
		for (int i = 0; i < bound; ++i) {
			F mid = (l + r) * F(1, 2);
			auto sm = draw_op2(list[ul], list[mr], list[ur], list[ml]);
			auto tm = draw_op2(list[dl], list[mr], list[dr], list[ml]);
			auto um = draw_op2(list[ul], list[ur], list[sm], list[tm]);
			auto dm = draw_op2(list[dl], list[dr], list[sm], list[tm]);
			auto mm = draw_op2(list[ml], list[mr], list[sm], list[tm]);
			if (mid == F(L, 1) + F(x, 1 << bound)) {
				return std::make_pair(um, dm);
			} else if (mid < F(L, 1) + F(x, 1 << bound)) {
				l = mid;
				ul = um;
				dl = dm;
				ml = mm;
			} else {
				r = mid;
				ur = um;
				dr = dm;
				mr = mm;
			}
		}
		return std::make_pair(P(), P());
	};

	auto parrallel_x_grid_binary_line = [&](int y, int bound, int L, int R) {
		F l = F(L, 1), r = F(R, 1);
		P ul(F(2, 1), F(L, 1)), ur(F(2, 1), F(R, 1)), dl(F(0, 1), F(L, 1)),
			dr(F(0, 1), F(R, 1)), ml(F(1, 1), F(L, 1)), mr(F(1, 1), F(R, 1));
		draw_op1(2, L), draw_op1(2, R), draw_op1(0, L), draw_op1(0, R), draw_op1(1, L),
			draw_op1(1, R);
		for (int i = 0; i < bound; ++i) {
			F mid = (l + r) * F(1, 2);
			auto sm = draw_op2(list[ul], list[mr], list[ur], list[ml]);
			auto tm = draw_op2(list[dl], list[mr], list[dr], list[ml]);
			auto um = draw_op2(list[ul], list[ur], list[sm], list[tm]);
			auto dm = draw_op2(list[dl], list[dr], list[sm], list[tm]);
			auto mm = draw_op2(list[ml], list[mr], list[sm], list[tm]);
			if (mid == F(L, 1) + F(y, 1 << bound)) {
				return std::make_pair(um, dm);
			} else if (mid < F(L, 1) + F(y, 1 << bound)) {
				l = mid;
				ul = um;
				dl = dm;
				ml = mm;
			} else {
				r = mid;
				ur = um;
				dr = dm;
				mr = mm;
			}
		}
		return std::make_pair(P(), P());
	};

	auto bound = [](int x) {
		for (int i = 31; i >= 0; --i) {
			if ((x >> i) & 1) return i + 1;
		}
		return 0;
	};

	auto shift_parrallel_x_line = [&](P ul, P um, P ur, i64 cur) -> std::pair<P, P> {
		auto dl = draw_op1(0, 0), dm = draw_op1(1, 0), dr = draw_op1(2, 0);
		auto Ul = draw_op1(0, 2), Um = draw_op1(1, 2), Ur = draw_op1(2, 2);
		auto sl = dl, sm = dm, sr = dr;
		auto [smdl, smul] = parrallel_y_grid_binary_line(1, 1, 0, 1);
		auto [smdr, smur] = parrallel_y_grid_binary_line(1, 1, 1, 2);
		int b = bound(cur);
		for (int i = b - 2; i >= 0; --i) {
			auto tmpl = draw_op2(list[smdl], list[smul], list[ul], list[ur]);
			auto stmpl = draw_op2(list[smdl], list[smul], list[sl], list[sr]);
			auto tmpr = draw_op2(list[smdr], list[smur], list[ul], list[ur]);
			auto stmpr = draw_op2(list[smdr], list[smur], list[sl], list[sr]);
			auto new_ul = draw_op2(list[dm], list[tmpl], list[dl], list[Ul]);
			auto new_ur = draw_op2(list[dm], list[tmpr], list[dr], list[Ur]);
			auto new_um = draw_op2(list[dm], list[Um], list[new_ul], list[new_ur]);
			auto new_sl = draw_op2(list[dm], list[stmpl], list[dl], list[Ul]);
			auto new_sr = draw_op2(list[dm], list[stmpr], list[dr], list[Ur]);
			auto new_sm = draw_op2(list[dm], list[Um], list[new_sl], list[new_sr]);

			auto next_l =
				draw_op2(list[new_sl], list[new_um], list[new_sm], list[new_ul]);
			auto next_r =
				draw_op2(list[new_sr], list[new_um], list[new_sm], list[new_ur]);

			new_sl = draw_op2(list[new_sl], list[new_ul], list[next_l], list[next_r]);
			new_sm = draw_op2(list[new_sm], list[new_um], list[next_l], list[next_r]);
			new_sr = draw_op2(list[new_sr], list[new_ur], list[next_l], list[next_r]);

			ul = new_ul, um = new_um, ur = new_ur;
			sl = new_sl, sm = new_sm, sr = new_sr;

			if ((cur >> i) & 1) {
				new_ul = draw_op2(list[ul], list[sl], list[um], list[sr]);
				new_ur = draw_op2(list[ur], list[sr], list[um], list[sl]);
				new_um = draw_op2(list[um], list[sm], list[new_ul], list[new_ur]);
				sl = ul, sm = um, sr = ur;
				ul = new_ul, um = new_um, ur = new_ur;
			}
		}
		return std::make_pair(ul, ur);
	};

	auto shift_parrallel_y_line = [&](P ul, P um, P ur, i64 cur) -> std::pair<P, P> {
		auto dl = draw_op1(0, 0), dm = draw_op1(0, 1), dr = draw_op1(0, 2);
		auto Ul = draw_op1(2, 0), Um = draw_op1(2, 1), Ur = draw_op1(2, 2);
		auto sl = dl, sm = dm, sr = dr;
		auto [smdl, smul] = parrallel_x_grid_binary_line(1, 1, 0, 1);
		auto [smdr, smur] = parrallel_x_grid_binary_line(1, 1, 1, 2);
		int b = bound(cur);
		for (int i = b - 2; i >= 0; --i) {
			auto tmpl = draw_op2(list[smdl], list[smul], list[ul], list[ur]);
			auto stmpl = draw_op2(list[smdl], list[smul], list[sl], list[sr]);
			auto tmpr = draw_op2(list[smdr], list[smur], list[ul], list[ur]);
			auto stmpr = draw_op2(list[smdr], list[smur], list[sl], list[sr]);
			auto new_ul = draw_op2(list[dm], list[tmpl], list[dl], list[Ul]);
			auto new_ur = draw_op2(list[dm], list[tmpr], list[dr], list[Ur]);
			auto new_um = draw_op2(list[dm], list[Um], list[new_ul], list[new_ur]);
			auto new_sl = draw_op2(list[dm], list[stmpl], list[dl], list[Ul]);
			auto new_sr = draw_op2(list[dm], list[stmpr], list[dr], list[Ur]);
			auto new_sm = draw_op2(list[dm], list[Um], list[new_sl], list[new_sr]);

			auto next_l =
				draw_op2(list[new_sl], list[new_um], list[new_sm], list[new_ul]);
			auto next_r =
				draw_op2(list[new_sr], list[new_um], list[new_sm], list[new_ur]);

			new_sl = draw_op2(list[new_sl], list[new_ul], list[next_l], list[next_r]);
			new_sm = draw_op2(list[new_sm], list[new_um], list[next_l], list[next_r]);
			new_sr = draw_op2(list[new_sr], list[new_ur], list[next_l], list[next_r]);

			ul = new_ul, um = new_um, ur = new_ur;
			sl = new_sl, sm = new_sm, sr = new_sr;

			if ((cur >> i) & 1) {
				new_ul = draw_op2(list[ul], list[sl], list[um], list[sr]);
				new_ur = draw_op2(list[ur], list[sr], list[um], list[sl]);
				new_um = draw_op2(list[um], list[sm], list[new_ul], list[new_ur]);
				sl = ul, sm = um, sr = ur;
				ul = new_ul, um = new_um, ur = new_ur;
			}
		}
		return std::make_pair(ul, ur);
	};

	auto [A, B] = [&parrallel_x_grid_binary_line, &parrallel_y_grid_binary_line, &bound,
				   &draw_op1, &draw_op2, &list, &shift_parrallel_x_line](i64 a, i64 b) {
		auto [A, B] = parrallel_y_grid_binary_line(b, bound(b), 0, 1);
		auto [C, D] = parrallel_y_grid_binary_line(b, bound(b), 1, 2);
		auto [E, F] = parrallel_x_grid_binary_line(1, bound(b), 0, 1);
		auto G = draw_op2(list[A], list[B], list[E], list[F]);
		auto H = draw_op2(list[C], list[D], list[E], list[F]);
		auto O = draw_op1(0, 0);
		auto Q = draw_op1(0, 2);
		auto I = draw_op1(1, 2);
		auto J = draw_op1(1, 0);
		auto K = draw_op2(list[G], list[O], list[I], list[J]);
		auto L = draw_op1(2, 2);
		auto M = draw_op1(2, 0);
		auto N = draw_op2(list[H], list[J], list[L], list[M]);
		auto P = draw_op2(list[K], list[N], list[O], list[Q]);
		auto [S, T] = shift_parrallel_x_line(P, K, N, a);
		return std::make_pair(S, T);
	}(c, d);

	auto [C, D] = [&parrallel_x_grid_binary_line, &parrallel_y_grid_binary_line, &bound,
				   &draw_op1, &draw_op2, &list, &shift_parrallel_y_line](i64 a, i64 b) {
		auto [A, B] = parrallel_x_grid_binary_line(b, bound(b), 0, 1);
		auto [C, D] = parrallel_x_grid_binary_line(b, bound(b), 1, 2);
		auto [E, F] = parrallel_y_grid_binary_line(1, bound(b), 0, 1);
		auto G = draw_op2(list[A], list[B], list[E], list[F]);
		auto H = draw_op2(list[C], list[D], list[E], list[F]);
		auto Q = draw_op1(2, 0);
		auto O = draw_op1(0, 0);
		auto I = draw_op1(2, 1);
		auto J = draw_op1(0, 1);
		auto K = draw_op2(list[G], list[O], list[I], list[J]);
		auto L = draw_op1(2, 2);
		auto M = draw_op1(0, 2);
		auto N = draw_op2(list[H], list[J], list[L], list[M]);
		auto P = draw_op2(list[K], list[N], list[O], list[Q]);
		auto [S, T] = shift_parrallel_y_line(P, K, N, a);
		return std::make_pair(S, T);
	}(a, b);

	draw_op2(list[A], list[B], list[C], list[D]);

	std::cout << answer.size() << '\n';
	for (auto i : answer) {
		for (int j = 0; j < (int)i.size(); ++j) {
			std::cout << i[j] << " \n"[j + 1 == i.size()];
		}
	}

	return 0;
}
