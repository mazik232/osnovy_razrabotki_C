#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        p = numerator;
        q = denominator;
        simplify();
    }

    friend ostream& operator<<(ostream& os, const Rational& rational) {
        os << rational.p << "/" << rational.q;
        return os;
    }
    friend istream& operator>>(istream& is, Rational& rational) {
        char slash, oper;
        int numerator1, denominator1, numerator2, denominator2;
        if (is >> numerator1 >> slash >> denominator1 >> oper >> numerator2 >> slash >> denominator2 && slash == '/') {
            if (oper == '+') {
                rational = Rational(numerator1, denominator1) + Rational(numerator2, denominator2);
            }
            else if (oper == '-') {
                rational = Rational(numerator1, denominator1) - Rational(numerator2, denominator2);
            }
            else if (oper == '*') {
                rational = Rational(numerator1, denominator1) * Rational(numerator2, denominator2);
            }
            else if (oper == '/') {
                rational = Rational(numerator1, denominator1) / Rational(numerator2, denominator2);
            }
        }
        else {
            is.setstate(ios::failbit);
        }
        return is;
    }

    Rational operator+(const Rational& rhs) {
        return Rational(p * rhs.q + q * rhs.p, q * rhs.q);
    }
    Rational operator-(const Rational& rhs) const {
        return Rational(p * rhs.q - q * rhs.p, q * rhs.q);
    }
    bool operator==(const Rational& rhs) const {
        return (p * rhs.q == q * rhs.p);
    }
    bool operator<(const Rational& rhs) const {
        return (p * rhs.q < q * rhs.p);
    }
    Rational operator*(const Rational& rhs) {
        return Rational(p * rhs.p, q * rhs.q);
    }
    Rational operator/(const Rational& rhs) {
        if (rhs.p == 0) {
            throw domain_error("Division by zero");
        }
        return Rational(p * rhs.q, q * rhs.p);
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return abs(a);
    }

    void simplify() {
        int gcd_value = gcd(p, q);
        p /= gcd_value;
        q /= gcd_value;
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
    }
};


int main()
{
    try {
        Rational calc;
        cin >> calc;
        cout << calc << endl;
        return 0;
    }
    catch (invalid_argument&) {
        cout << "Invalid argument";
    }
    catch (domain_error&) {
        cout << "Division by zero";
    }
}

