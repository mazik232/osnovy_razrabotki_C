#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    int days = 0;
    const vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<vector<string>> taskday(months[days]);

    for (int i = 0; i < Q; Q++) {
        string operation;
        cin >> operation;
        if (operation == "ADD") {
            int day;
            string task;
            cin >> day >> task;
            --day;
            taskday[day].push_back(task);
        }
        else if (operation == "DUMP") {
            int day;
            cin >> day;
            --day;
            cout << taskday[day].size() << " ";
            for (const string& x : taskday[day]) {
                cout << x << " ";
            }
            cout << endl;
        }
        else if (operation == "NEXT") {
            const int old_month_length = months[days];
            days = (days + 1) % 12;
            const int new_month_length = months[days];
            if (new_month_length < old_month_length) {
                vector<string>& taskday_last = taskday[new_month_length-1];
                for (int day = new_month_length; day < old_month_length; ++day) {
                    taskday_last.insert(end(taskday_last), begin(taskday[day]), end(taskday[day]));
                }
            }
        taskday.resize(months[days]);
        }
    }
}
