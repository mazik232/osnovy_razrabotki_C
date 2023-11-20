﻿#include <iostream>
#include <map>


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

    /* ??? */ Find(const Date& date) const;

    void Print() const;

    void DoSomething(const map<int, int>& m) {
        // ...
        if (m.count(key) > 0) {
            value = m.at(key);
        }

    }
};

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        // Считайте команды с потока ввода и обработайте каждую
    }

    return 0;
}