class Fraction {
private:
	long long gcd(long long a, long long b) { for (; b; a %= b, swap(a, b)); return a; }

public:
	long long numerator, denominator;

	Fraction() {
		numerator = 0;
		denominator = 1;
	}

	Fraction(long long n, long long d) {
		if (d == 0) {
			assert(0);
		}
		else if (n == 0) {
			numerator = 0;
			denominator = 1;
		}
		else {
			int sign = 1;
			if (n < 0) {
				sign *= -1;
				n *= -1;
			}
			if (d < 0) {
				sign *= -1;
				d *= -1;
			}

			long long tmp = gcd(n, d);
			numerator = n / tmp*sign;
			denominator = d / tmp;
		}
	}

	bool operator==(const Fraction& F)const {
		return (this->denominator*F.numerator == this->numerator*F.denominator);
	}

	bool operator!=(const Fraction& F)const {
		return (this->denominator*F.numerator != this->numerator*F.denominator);
	}

	operator int() { return (numerator) / denominator; }
	operator float() { return ((float)numerator) / denominator; }
	operator double() { return ((double)numerator) / denominator; }
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	Fraction tmp(lhs.numerator*rhs.denominator
		+ rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator);
	return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
	Fraction tmp(lhs.numerator*rhs.denominator
		+ rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator);
	lhs = tmp;
	return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	Fraction tmp(lhs.numerator*rhs.denominator
		- rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator);
	return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
	Fraction tmp(lhs.numerator*rhs.denominator
		- rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator);
	lhs = tmp;
	return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	Fraction tmp(lhs.numerator*rhs.numerator,
		lhs.denominator*rhs.denominator);
	return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
	Fraction tmp(lhs.numerator*rhs.numerator,
		lhs.denominator*rhs.denominator);
	lhs = tmp;
	return lhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
	Fraction tmp(lhs*rhs.numerator, rhs.denominator);
	return tmp;
}

Fraction operator*(const Fraction& rhs, int lhs) {
	Fraction tmp(lhs*rhs.numerator, rhs.denominator);
	return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	Fraction tmp(lhs.numerator*rhs.denominator,
		lhs.denominator*rhs.numerator);
	return tmp;
}

ostream& operator<<(ostream &strm, const Fraction &a) {
	if (a.denominator == 1) {
		strm << a.numerator;
	}
	else {
		strm << a.numerator << "/" << a.denominator;
	}
	return strm;
}
