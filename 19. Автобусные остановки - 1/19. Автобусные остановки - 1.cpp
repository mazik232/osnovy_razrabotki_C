
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> PereborStop(const string& stop, const map<string, vector<string>> buses) {
    vector<string> a;
    for (const auto& x : buses) {
        for (const auto& i : x.second) {
            if (i == stop) {
                a.push_back(x.first);
            }
        }
    }
    return a;
}

vector<string> PereborStopBus(const string& stop, const map<string, vector<string>> buses, const vector<string> unordered_bus) {
    vector<string> a, b;
    a = PereborStop(stop, buses);
        if (a.size() != 0) {
            for (int k = 0; k < unordered_bus.size(); k++) {
                for (int j = 0; j < a.size(); j++) {
                    if (unordered_bus[k] == a[j])
                        b.push_back(unordered_bus[k]);
                }
            }
        }
        else {
            b.size();
        }
        return b;
}

void PrintVector(const vector<string> a) {
    for (auto& i : a) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int Q;
    cin >> Q;
    map<string, vector<string>> buses;
    vector<string> unordered_bus;
    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            unordered_bus.push_back(bus);
            vector<string> stop(stop_count);
            for (int i = 0; i < stop_count; i++) {
                cin >> stop[i];
            }
            buses[bus] = stop;
        }
        else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            vector<string> bus;
            bus = PereborStopBus(stop, buses, unordered_bus);
            if (bus.empty()) {
                cout << "No stop " << endl;
            }
            else {
                PrintVector(bus);
            }  
        }
        else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            vector<string> x;
            if (buses.count(bus) == 1) {
                for (const auto& i : buses[bus]) {
                    x = PereborStopBus(i, buses, unordered_bus);
                    cout << "Stop " << i << ": ";
                    if (x.size() == 1) {
                        cout << "no interchange ";
                    }
                    else {
                        for (int j = 0; j < x.size(); j++) {
                            if (x[j] == bus) {
                                j++;
                            }
                            else {
                                cout << x[j] << " ";
                            }
                        }

                    }
                    cout << endl;
                }
            }
            else if (buses.count(bus) == 0) {
                cout << "No bus" << endl;
            }
        }
        else if (command == "ALL_BUSES") {
            if (buses.size() != 0) {
                for (auto &x : buses) {
                    cout << "Bus " << x.first << ": ";
                    for (auto i : x.second) {
                        cout << i << " ";
                    }
                    cout << endl;
                }
            }
            else if (buses.size() == 0) {
                cout << "No buses" << endl;
            }
        }
    }

}


