#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    string last_name;
    int day;
    int month;
    int year;
};

int main()
{
    int N;
    cin >> N;
    if (N >= 0 && N <= 10000) {
        vector<Student> students;
        Student table;
        for (int i = 0; i < N; i++) {
            cin >> table.name >> table.last_name >> table.day >> table.month >> table.year;
            students.push_back(table);
        }
        int M;
        cin >> M;
        if (M >= 0 && M <= 10000) {
            for (int j = 0; j < M; j++) {
                string request;
                int number;
                cin >> request >> number;
                if ((request.length() > 0 && request.length() <= 15) && (number > 0 && number <= 1000000000)) {
                    if (request == "name") {
                        cout << students[number-1].name << " " << students[number-1].last_name << endl;
                    }
                    else if (request == "date") {
                        cout << students[number-1].day << "." << students[number-1].month << "." << students[number-1].year << endl;
                    }
                    else {
                        cout << "bad request" << endl;
                    }
                }
                else {
                    cout << "bad request" << endl;
                }
            }  
        }
        else {
            cout << "bad request" << endl;
        }
    }
    else {
        cout << "bad request";
    }
}
