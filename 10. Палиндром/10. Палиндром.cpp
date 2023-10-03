#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool IsPalindrom(string a) {
    vector<char> c,y;
    for (auto b : a) {
        c.push_back(b);
    }
    for (int i = c.size()-1; i >= 0; --i) {
        y.push_back(c[i]);
    }
    if (c == y) {
        return true;
    }
    return false;
}

int main()
{
    string a;
    cin >> a;
    cout << IsPalindrom(a);

}
