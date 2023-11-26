#include <algorithm>
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