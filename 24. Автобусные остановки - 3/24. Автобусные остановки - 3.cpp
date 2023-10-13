#include <iostream>
#include <map>
#include <set>

using namespace std;



int main()
{
    int q;
    int num = 1;
    cin >> q;
    map <set<string>, int> stop_buses;
    while (q > 0) {
        int n;
        set<string> stops;
        cin >> n;
        for (int i=0; i < n; i++) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        if (stop_buses.count(stops) == 1) {
            cout << "Already exists for " << stop_buses[stops] << endl;
        }
        else {
            stop_buses[stops] = num;
            cout << "New bus " << num << endl;
            num++;
        }
    }
}


