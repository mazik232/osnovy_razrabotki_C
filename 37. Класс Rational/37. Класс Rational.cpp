﻿#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <set>
#include <iterator>
#include <stdexcept>

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
        char slash;
        int numerator, denominator;
        if (is >> numerator >> slash >> denominator && slash == '/') {
            rational = Rational(numerator, denominator);
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

    int main() {
        //Первая часть
        {
            const Rational r(3, 10);
            if (r.Numerator() != 3 || r.Denominator() != 10) {
                cout << "Rational(3, 10) != 3/10" << endl;
                return 1;
            }
        }

        {
            const Rational r(8, 12);
            if (r.Numerator() != 2 || r.Denominator() != 3) {
                cout << "Rational(8, 12) != 2/3" << endl;
                return 2;
            }
        }

        {
            const Rational r(-4, 6);
            if (r.Numerator() != -2 || r.Denominator() != 3) {
                cout << "Rational(-4, 6) != -2/3" << endl;
                return 3;
            }
        }

        {
            const Rational r(-4, -6);
            if (r.Numerator() != 2 || r.Denominator() != 3) {
                cout << "Rational(-4, -6) != -2/3" << endl;
                return 3;
            }
        }

        {
            const Rational r(0, 15);
            if (r.Numerator() != 0 || r.Denominator() != 1) {
                cout << "Rational(0, 15) != 0/1" << endl;
                return 4;
            }
        }

        {
            const Rational defaultConstructed;
            if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
                cout << "Rational() != 0/1" << endl;
                return 5;
            }
        }
        cout << "OK first test" << endl;
        //Вторая часть
        {
            Rational r1(4, 6);
            Rational r2(2, 3);
            bool equal = r1 == r2;
            if (!equal) {
                cout << "4/6 != 2/3" << endl;
                return 1;
            }
        }

        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a + b;
            bool equal = c == Rational(2, 1);
            if (!equal) {
                cout << "2/3 + 4/3 != 2" << endl;
                return 2;
            }
        }

        {
            Rational a(5, 7);
            Rational b(2, 9);
            Rational c = a - b;
            bool equal = c == Rational(31, 63);
            if (!equal) {
                cout << "5/7 - 2/9 != 31/63" << endl;
                return 3;
            }
        }
        cout << "OK second test" << endl;
        //Третья часть
        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a * b;
            bool equal = c == Rational(8, 9);
            if (!equal) {
                cout << "2/3 * 4/3 != 8/9" << endl;
                return 1;
            }
        }

        {
            Rational a(5, 4);
            Rational b(15, 8);
            Rational c = a / b;
            bool equal = c == Rational(2, 3);
            if (!equal) {
                cout << "5/4 / 15/8 != 2/3" << endl;
                return 2;
            }
        }

        cout << "OK third test" << endl;
        //Четвертая часть
        {
            ostringstream output;
            output << Rational(-6, 8);
            if (output.str() != "-3/4") {
                cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
                return 1;
            }
        }

        {
            istringstream input("5/7");
            Rational r;
            input >> r;
            bool equal = r == Rational(5, 7);
            if (!equal) {
                cout << "5/7 is incorrectly read as " << r << endl;
                return 2;
            }
        }

        {
            istringstream input("");
            Rational r;
            bool correct = !(input >> r);
            if (!correct) {
                cout << "Read from empty stream works incorrectly" << endl;
                return 3;
            }
        }

        {
            istringstream input("5/7 10/8");
            Rational r1, r2;
            input >> r1 >> r2;
            bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
                return 4;
            }

            input >> r1;
            input >> r2;
            correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
                return 5;
            }
        }

        {
            istringstream input1("1*2"), input2("1/"), input3("/4");
            Rational r1, r2, r3;
            input1 >> r1;
            input2 >> r2;
            input3 >> r3;
            bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
            if (!correct) {
                cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                    << r1 << " " << r2 << " " << r3 << endl;

                return 6;
            }
        }

        {
            istringstream input("2/4/6/8");
            Rational r1;
            input >> r1;
            bool correct = r1 == Rational(1, 2);
            if (!correct) {
                cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
                return 7;
            }
        }

        cout << "OK four test" << endl;
        //Пятая часть
        {
            const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
            if (rs.size() != 3) {
                cout << "Wrong amount of items in the set" << endl;
                return 1;
            }

            vector<Rational> v;
            for (auto x : rs) {
                v.push_back(x);
            }
            if (v != vector<Rational>{{1, 25}, { 1, 2 }, { 3, 4 }}) {
                cout << "Rationals comparison works incorrectly" << endl;
                return 2;
            }
        }

        {
            map<Rational, int> count;
            ++count[{1, 2}];
            ++count[{1, 2}];

            ++count[{2, 3}];

            if (count.size() != 2) {
                cout << "Wrong amount of items in the map" << endl;
                return 3;
            }
        }
        cout << "OK five test" << endl;
        //Исключение
        try {
            Rational r(1, 0);
            cout << "Doesn't throw in case of zero denominator" << endl;
            return 1;
        }
        catch (invalid_argument&) {
        }

        try {
            auto x = Rational(1, 2) / Rational(0, 1);
            cout << "Doesn't throw in case of division by zero" << endl;
            return 2;
        }
        catch (domain_error&) {
        }

        cout << "OK" << endl;
        return 0;

    }