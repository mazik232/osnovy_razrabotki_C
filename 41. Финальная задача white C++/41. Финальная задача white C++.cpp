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
        char delimiter = '-';
        ss >> year >> delimiter >> month >> delimiter >> day;
        if (ss.fail() || ss.peek() != EOF) {
            throw runtime_error("Wrong date format: " + date);
        }
        if (month < 1 || month > 12) {
            throw runtime_error("Month value is invalid: " + to_string(month));
        }
        if (day < 1 || day > 31) {
            throw runtime_error("Day value is invalid: " + to_string(day));
        }
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
            try {
                Date date(dateStr);
                db.AddEvent(date, event);
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
            }
        }
        else if (str == "Del") {
            ss >> dateStr >> event;
            try {
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
            catch (exception& ex) {
                cout << ex.what() << endl;
            }    
        }
        else if (str == "Find") {
            ss >> dateStr;
            try {
                Date date(dateStr);
                db.Find(date);
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
            }
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

