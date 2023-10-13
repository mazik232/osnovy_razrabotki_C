#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> unique_string;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string string;
        cin >> string;
        unique_string.insert(string);
    }
    cout << unique_string.size() << endl;
}

