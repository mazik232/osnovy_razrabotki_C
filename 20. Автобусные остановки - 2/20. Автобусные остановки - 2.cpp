
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



int main()
{
    int Q;
    cin >> Q;
    map<vector<string>, int> bus_stops;
    int bus_count = 1;
    for (int i = 0; i < Q; i++) {
        int num;
        cin >> num;
        vector<string> stops(num);
        for (auto& i : stops) {
            cin >> i;
        }
        auto result = bus_stops.find(stops);
        if (result == bus_stops.end()) {
            cout << "New bus " << bus_count << endl;
            bus_stops[stops] = bus_count;
            bus_count++;
        }
        else {
            cout << "Already exists for " << result->second << endl;
        }
    }
}
