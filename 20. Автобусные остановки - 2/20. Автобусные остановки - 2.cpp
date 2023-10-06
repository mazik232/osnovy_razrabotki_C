
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



int main()
{
    int Q;
    cin >> Q;
    map<int, vector<string>> bus_stops;
    int bus_count = 0;
    for (int i = 0; i < Q; i++) {
        int num;
        cin >> num;
        vector<string> stops(num);
        for (auto& i : stops) {
            cin >> i;
        }
        bus_count++;
        for (auto& x : bus_stops) {
            if (x.second == stops) {
                cout << "Already exists for " << x.first << endl;
            }
            else {
                bus_stops[bus_count] = stops;
                cout << "New bus " << bus_count << endl;
            }
        }

    }
}
