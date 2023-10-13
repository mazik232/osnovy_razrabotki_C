#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    for (auto& x : m) {
        s.insert(x.second);
    }
    return s;
}

int main()
{
    set<string> values = BuildMapValuesSet({
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}
        });

    for (const string& value : values) {
        cout << value << endl;
    }
}

