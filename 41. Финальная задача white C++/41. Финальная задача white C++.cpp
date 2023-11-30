#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

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
    if (lhs.GetDay() < rhs.GetDay()) {
        if (lhs.GetMonth() < rhs.GetMonth()) {
            if (lhs.GetYear() < rhs.GetYear()) {
                return 1;
            }
        }
    }
    else {
        return 0;
    }
    
}


class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        auto it = date_events.find(date);
        if (it != date_events.end()) {
            it->second.push_back(event);
        }
        else {
            date_events[date] = { event };
        }
    }
    bool DeleteEvent(const Date& date, const string& event) {
        auto it = date_events.find(date);
        if (it != date_events.end()) {
            vector<string>& events = it->second;
            for (auto it_event = events.begin(); it_event != events.end(); ++it_event) {
                if (*it_event == event) {
                    events.erase(it_event);
                    return 1;
                }
            }
        }
        return 0;
    }
    int  DeleteDate(const Date& date) {
        int num_events = 0;
        if (date_events.count(date) > 0) {
            num_events = date_events.at(date).size();
            date_events.erase(date);
        }
        return num_events;
    }

    void Find(const Date& date) const {
        vector<string> events;
        if (date_events.count(date) > 0) {
            events = date_events.at(date);
            for (auto& i : events) {
                cout << i << endl;
            }
        }
        else {
            cout << "Events not found in date " << date.GetYear() << "-" << date.GetMonth() << "-" << date.GetDay() << endl;
        }
    }

    void Print() const {
        for (const auto& i : date_events) {
            for (const auto& x : i.second) {
                cout << setw(4) << setfill('0') << i.first.GetYear();
                cout << "-" << setw(2) << setfill('0') << i.first.GetMonth();
                cout << "-" << setw(2) << setfill('0') << i.first.GetDay() << " " << x << endl;
            }
        }
    }

private:
    map<Date, vector<string>> date_events;
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

