﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


struct full_name {
    string fName;
    string lName;
};


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        full_names[year].fName = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        full_names[year].lName = last_name;
    }
    string GetFullName(int year) {
        string a;
        string name = "";
        string soname = "";
        int x = 0;
        int y = 0;
        for (auto i = full_names.rbegin(); i != full_names.rend(); ++i) {
            if (i->first <= year) {
                if (i->second.fName != "" && x == 0) {
                    name = i->second.fName;
                    x++;
                }
                if (i->second.lName != "" && y == 0) {
                    soname = i->second.lName;
                    y++;
                }
            }
        }
        if (name != "" && soname == "") {
            a = name + " with unknown last name";
        }
        else if (name == "" && soname != "") {
            a = soname + " with unknown first name";
        }
        else if (name != "" && soname != "") {
            a = name + " " + soname;
        }
        else {
            a = "Incognito";
        }
        return a;
    }
    string GetFullNameWithHistory(int year) {
        string a;
        string name, soname, nname, ssoname;
        int x = 0;
        int y = 0;
        int n = 0;
        int o = 0;
        for (auto i = full_names.rbegin(); i != full_names.rend(); ++i) {
            if (i->first <= year) {
                if (i->second.fName != "") {
                    if (x == 1) {
                        if (n > 0) {
                            nname = nname + ", ";
                        }
                        nname += i->second.fName;
                        n++;
                    }
                    if (x == 0) {
                        name = i->second.fName;
                        x++;
                    }
                    if (name == nname) {
                        nname = "";
                        n = 0;
                    }
                }
                if (i->second.lName != "") {
                    if (y == 1) {
                        if (o > 0) {
                            ssoname = ssoname + ", ";
                        }
                        ssoname += i->second.lName;
                        o++;
                    }
                    if (y == 0) {
                        soname = i->second.lName;
                        y++;
                    }
                    if (soname == ssoname) {
                        ssoname = "";
                        o = 0;
                    }
                }
            }
        }
        if (nname != "") {
            nname = " (" + nname + ")";
        }
        if (ssoname != "") {
            ssoname = " (" + ssoname + ")";
        }
        if (name != "" && soname == "") {
            a = name + nname + " with unknown last name";
        }
        else if (name == "" && soname != "") {
            a = soname + ssoname + " with unknown first name";
        }
        else if (name != "" && soname != "") {
            a = name + nname + " " + soname + ssoname;
        }
        else {
            a = "Incognito";
        }
        return a;
    }
private:
    map<int, full_name> full_names;
};

int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
}