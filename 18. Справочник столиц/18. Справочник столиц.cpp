
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void PrintDump(const map<string, string>& dump) {
    for (auto item : dump) {
        cout << item.first << "/" << item.second << " ";
    }
    cout << endl;
}


int main()
{
    int Q;
    cin >> Q;
    map<string, string> country_with_capitals;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (country_with_capitals.count(country) == 0) {
                country_with_capitals[country] = new_capital;
                cout << "Introduce new  country " << country << " with capital " << new_capital << endl;
            }
            else if (country_with_capitals.count(country) == 1) {
                if (country_with_capitals[country] == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                }
                else if (country_with_capitals[country] != new_capital) {
                    cout << "Country " << country << " has changed its capital from " << country_with_capitals[country] << " to " << new_capital << endl;
                    country_with_capitals[country] = new_capital;
                }
            }
        }
        else if (command == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || country_with_capitals.count(old_country_name) == 0 || country_with_capitals.count(new_country_name) == 1) {
                cout << "Incorrect rename, skip" << endl;
            }
            else if (country_with_capitals.count(old_country_name) == 1) {
                string capital;
                capital = country_with_capitals[old_country_name];
                country_with_capitals.erase(old_country_name);
                country_with_capitals[new_country_name] = capital;
                cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
            }
        }
        else if (command == "ABOUT") {
            string country;
            cin >> country;
            if (country_with_capitals.count(country) == 1) {
                cout << "Country " << country << " has capital " << country_with_capitals[country] << endl;
            }
            else {
                cout << "Country " << country << " doesn't exist" << endl;
            }
        }
        else if (command == "DUMP") {
            if (country_with_capitals.size() == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                PrintDump(country_with_capitals);
            }
        }
    }
}

