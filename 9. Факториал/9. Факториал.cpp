#include <iostream>


using namespace std;


int faktorial(int x) {
    int y = 1;
    for (int i = 1; i <= x; i++) {
        y =y*i;
    }
    return y;
}

int main()
{
    int a;
    cin >> a;
    a = faktorial(a);
    cout << a;
}

