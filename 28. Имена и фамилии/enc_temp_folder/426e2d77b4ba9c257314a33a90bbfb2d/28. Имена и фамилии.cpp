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
    void ChangeFirstName(int year, const string& first_name) {
        full_names[year].fName = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        full_names[year].lName = last_name;
    }
    string GetFullName(int year) {
<<<<<<< HEAD

=======
        string a;
        int element;
        string name, soname;
        if (full_names.count(year) == 0) {
            for (auto i : full_names) {
                    if (i.second.fName != "" && i.first < year) {
                        name = i.second.fName;
                        element = i.first;
                    }
                    if (i.second.lName != "" && i.first < year) {
                        soname = i.second.lName;
                        element = i.first;
                    }   
                }
            if (element < year) {
                a = name + " " + soname;
            }
            else {
                a = "Incognito";
            }
        }
        else if (full_names.count(year) != 0) {
            if (full_names[year].lName == "") {
                a = full_names[year].fName + " with unknown last name";
            }
            else if (full_names[year].fName == "") {
                a = full_names[year].lName + " with unknown first name";
            }
            else {
                a = full_names[year].fName + " " + full_names[year].lName;
            }
        }
        return a;
>>>>>>> white
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
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

}

