#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a;
    int s = 0;
    cin >> a;
    vector<int> b(a);
    for (int& temp : b) {
        cin >> temp;
        s += temp;
    }
    s /= a;
    //cout << s;
    vector<int> result;
    for (int i = 0; i < a; ++i) {
        if (b[i] > s) {
            result.push_back(b[i]);
        }
    }
    cout << result.size() << endl;
    for (int index : result) {
        cout << index << " ";
    }
}

