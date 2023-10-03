
#include <iostream>
#include <vector>
#include <string>

using namespace std;



void perem(vector<string>& source, vector<string>& destination) {
    for (string x : source) {
        destination.push_back(x);
    }
    source.clear();

}

int main()
{
    vector<string> a = { "a", "b", "c" };
    vector<string> b = { "z" };
    perem(a, b);
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }

}


