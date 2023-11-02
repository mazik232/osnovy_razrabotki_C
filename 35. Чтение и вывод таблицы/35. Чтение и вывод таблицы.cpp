#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Readtext(const string& text) {
    vector<int> values;
    int N = 0;
    int M = 0;
    int line = 0;
    ifstream input(text);
    if (input) {
        input >> N;
        input.ignore(1);
        input >> M;
        input.ignore(1);
        cout << N << " " << M << endl;
        while (M) {
            input >> line;
            cout << line << " ";
            M--;
        }
    }
    else {
        cout << "file not found" << endl;
    }
}

int main()
{
    const string text = "input.txt";
    Readtext(text);

}

