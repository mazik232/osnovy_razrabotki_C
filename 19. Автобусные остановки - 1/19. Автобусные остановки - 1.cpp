
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

bool PereborStopBool(string& stop, map<string, vector<string>>& buses) {
    for (const auto& x : buses) {
        for (const auto& i : x.second) {
            if (i == stop) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

void PereborStop(const string& stop, map<string, vector<string>> buses) {
    for (auto& x : buses) {
        for (auto &i : x.second) {
            if (i == stop) {
                cout << x.first << " ";
            }
        }
    }
}

void PereborBus(const string& bus, map<string, vector<string>> buses) {

}


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
            buses[bus] = stop;
        }
        else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (PereborStopBool(stop, buses) == 1) {
                PereborStop(stop, buses);
                cout << endl;
            }
            else {
                cout << "No stop" << endl;
            }
        }
        else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus) == 1) {

                //cout << "Bus " << bus << ": " << PereborBus(bus, buses) << endl;
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
                }
            }
            else if (buses.size() == 0) {
                cout << "No buses" << endl;
            }
        }
    }

}


