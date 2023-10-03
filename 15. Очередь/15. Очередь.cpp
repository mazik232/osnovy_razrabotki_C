#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
    int a;
    cin >> a;
    int value;
    int quantity;
    vector<bool> b;
    for (int i = 0; i < a; i++) {
        string command;
        cin >> command;
        if (command == "WORRY_COUNT") {
            cout << count(begin(b), end(b), true) << endl;
        }
        else if (command == "WORRY") {
            cin >> value;
            b[value] = true;
        }
        else if (command == "COME") {
            cin >> quantity;
            b.resize(b.size()+quantity, false);
        }
        else if (command == "QUIET") {
            int countt = 0;
            cin >> countt;
            b[countt] = false;
        }
    }


}

