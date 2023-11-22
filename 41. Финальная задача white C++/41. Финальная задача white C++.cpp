#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;



class Date {
public:
    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

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
        Date date;
        string event, str;
        date.GetYear();
        date.GetMonth();
        date.GetDay();
        if (str == "Add") {
            db.AddEvent(date, event);
        }
        else if (str == "Del") {
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
            db.Find(date);;
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