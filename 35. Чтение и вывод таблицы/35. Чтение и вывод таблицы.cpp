#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Readtext(const string& text) {
    vector<int> values;
    int N = 0;
    int M = 0;
    ifstream input(text);
    if (input) {
        string line;
        getline(input, N, ',');
        getline(input, M, '/n');
        while (getline(input, line, ',')) {
            N = line;
        }
    }
}

int main()
{
    const string text = "input.txt";
    Readtext(text);

}

