#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>


using namespace std;


int GreatestCommonDivisor(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GreatestCommonDivisor(b, a % b);
	}
}

class Rational
{
public:
	Rational()
	{
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator)
	{
		if (denominator == 0) {
			throw exception();
		}
		const int gcd = GreatestCommonDivisor(numerator, denominator);
		p = numerator / gcd;
		q = denominator / gcd;
		if (q < 0) {
			p = -p;
			q = -q;
		}
	}

	int Numerator() const
	{
		return p;
	}

	int Denominator() const
	{
		return q;
	}
private:
	int p;
	int q;
};

bool operator==(const Rational& rhs, const Rational& lhs) {
	if (rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator()) {
		return true;
	}
	else {
		return false;
	}
}
Rational operator+(const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()
	};
}
Rational operator / (const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
		throw exception();
	}
	return {
		lhs * Rational(rhs.Denominator(), rhs.Numerator())
	};
}

istream& operator >> (istream& is, Rational& r) {
	int n, d;
	char c;
	if (is) {
		is >> n >> c >> d;
		if (is && c == '/') {
			r = Rational(n, d);
		}
	}
	return is;
}


ostream& operator << (ostream& os, const Rational& r) {
	return os << r.Numerator() << "/" << r.Denominator();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

int main()
{
	try
	{
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&)
	{

	}

	try
	{
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&)
	{

	}

	cout << "OK" << endl;
	return 0;
}