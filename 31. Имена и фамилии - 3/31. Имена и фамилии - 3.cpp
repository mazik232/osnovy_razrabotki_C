#include <iostream>
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
    Person(const string& n_name, const string& s_soname, int y_year) {
        full_names[y_year] = { n_name, s_soname };
        birth_year = y_year;
        for (auto& i : full_names) {
            if (i.first < y_year) full_names.erase(i.first);
        }
    }
    void ChangeFirstName(int year, const string& first_name) {
        full_names[year].fName = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        full_names[year].lName = last_name;
    }
    string GetFullName(int year) {
        if (year < birth_year) return "No person";
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
        if (year < birth_year) return "No person";
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
    int birth_year = 0;
};

int main()
{
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1959, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}