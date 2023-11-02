#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<vector<int>> Readtext(const string& text) {
    ifstream input(text);
    string line;
    if (input.is_open()) {
        getline(input, line);
        stringstream ss(line);
        int N, M;
        ss >> N >> M;
        vector <vector<int>> table(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            getline(input, line);
            stringstream ss(line);
            for (int j = 0; j < M; j++) {
                string value;
                getline(ss, value, ',');
                table[i][j] = stoi(value);
            }
        }
        return table;
    }
    else {
        cout << "file not found" << endl;
    }
}

void PrintText(const vector<vector<int>>&table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout << setw(10);
            cout << table[i][j] << " ";  
        }
        cout << endl;
    }
}

int main()
{
    const string text = "input.txt"; 
    PrintText(Readtext(text));

}

