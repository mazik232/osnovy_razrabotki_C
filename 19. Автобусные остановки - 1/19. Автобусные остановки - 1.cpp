
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;




int main()
{
    int Q;
    cin >> Q;
    map<string, vector<string>> buses;
    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            vector<string> stop(stop_count);
            for (int i = 0; i < stop_count; i++) {
                cin >> stop[i];
            }
            for (auto x : stop) {
                cout << x << " ";
            }
        }
        else if (command == "BUSES_FOR_STOP") {

        }
        else if (command == "STOPS_FOR_BUS") {

        }
        else if (command == "ALL_BUSES") {

        }
    }

}


