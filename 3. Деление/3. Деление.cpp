
#include <iostream>
#include <cmath>

using namespace std;

int main()
{   
    int a, b;
    cin >> a >> b;
    if (a >= 0 && a <= 1000000) {
        if (b >= 1 && b <= 1000000) {
            int x = a / b;
            cout << x;
        }
        else if (b == 0) {
            cout << "impossible";
        }
    }
}

