#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> Perebor(const string& word) {
    map<char, int> counters;
    for (char c : word) {
        ++counters[c];
    }
    return counters;
}

int main()
{
    int value;
    cin >> value;
    map<string, string> words;
    for (int i = 0; i < value; i++) {
        string word_one, word_two;
        cin >> word_one >> word_two;
        if (Perebor(word_one) == Perebor(word_two)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}