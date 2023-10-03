#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string a) {
    vector<char> c, y;
    for (auto b : a) {
        c.push_back(b);
    }
    for (int i = c.size() - 1; i >= 0; --i) {
        y.push_back(c[i]);
    }
    if (c == y) {
        return true;
    }
    return false;
}

vector<string> PalindromFilter(vector<string> a, int min_Len) {
    vector<string> result;
    for (auto x : a) {
        if (x.size() >= min_Len && IsPalindrom(x)) {
            result.push_back(x);
        }
    }
    return result;
}

int main()
{
    vector<string> a = { { "weew" }, { "bro" }, {"code"}};
    int minLength;
    cin >> minLength;
    a = PalindromFilter(a, minLength);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}