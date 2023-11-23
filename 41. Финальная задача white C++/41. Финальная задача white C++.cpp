#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<sstream>

using namespace std;



class Date {
public:
    Date(string date) {
        stringstream ss(date);
        char delimiter;
        ss >> year >> delimiter >> month >> delimiter >> day;
    }

    int GetYear() const {
        return year;
    }

    int GetMonth() const {
        return month;
    }

    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    return 1;
}



class Database {
public:
    void AddEvent(const Date& date, const string& event) {


    }
    bool DeleteEvent(const Date& date, const string& event) {

        return 0;
    }
    int  DeleteDate(const Date& date) {
        return 0;
    }

    void Find(const Date& date) const {

    }

    void Print() const {

    }

    void DoSomething(const map<int, int>& m) {
        // ...
        //if (m.count(key) > 0) {
            //value = m.at(key);
        //}
    }
};
int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        string dateStr, event, str;
        stringstream ss(command);
        ss >> str;
        if (str == "Add") {
            ss >> dateStr >> event;
            Date date(dateStr);
            db.AddEvent(date, event);
        }
        else if (str == "Del") {
            ss >> dateStr >> event;
            Date date(dateStr);
            if (event.empty()) {
                cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
            }
            else {
                if (db.DeleteEvent(date, event)) {
                    cout << "Deleted successfully" << endl;
                }
                else {
                    cout << "Event not found" << endl;
                }
            }
        }
        else if (str == "Find") {
            ss >> dateStr;
            Date date(dateStr);
            db.Find(date);
        }
        else if (str == "Print") {
            db.Print();
        }
        else {
            cout << "Unknown command: " << str << endl;
        }
    }
    return 0;
}

