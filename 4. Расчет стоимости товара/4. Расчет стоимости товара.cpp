#include <iostream>

using namespace std;


int main()
{
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (a < b) {
        if (n > a) {
            if (n > b) {
                n *= (100 - y) * 0.01;
                cout << n;
            }
            else {
            n *= (100 - x) * 0.01;
            cout << n;
            }
        }
        else if (n <= a) {
            cout << n;
        }
    }
    else {
        cout << n;
    }
}

