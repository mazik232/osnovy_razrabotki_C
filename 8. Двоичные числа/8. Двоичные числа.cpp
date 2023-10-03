#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    while (n != 0) {
        v.push_back(n%2);
        n /= 2;
    }
    reverse(v.begin(), v.end());
        for (int c : v) {
            cout << c << " ";
        }
}

