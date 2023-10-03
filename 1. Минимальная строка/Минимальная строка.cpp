#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    vector<string> minstroka = { a, b, c };
    auto min = min_element(begin(minstroka), end(minstroka));
    cout << "min = " << *min;
}
