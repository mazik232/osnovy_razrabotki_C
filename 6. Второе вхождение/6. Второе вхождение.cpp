#include <iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int rez = -2;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 'f') {
            if (rez == -2) {
                rez = -1;
            }
            else if (rez == -1) {
                rez = i;
                break;
            }
        }
    }
    cout << rez;

}


