#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVector(const vector<string>& a) {
    for (const auto& i : a) {
        cout << i << " ";
    }
}

string str_to_low(const string& s) {
    string res;
    for (auto i : s) {
        res += tolower(i);
    }
    return res;
}

bool reg(const string& a, const string& b) {
    return str_to_low(a) < str_to_low(b);
}

int main()
{
    int n;
    cin >> n;
    if (n >= 0 && n <= 1000) {
        vector<string> words(n);
        for (int i = 0; i < words.size(); i++) {
            string word;
            cin >> word;
            if (word.length() <= 15) {
                words[i] = word;
            }
        }
        sort(begin(words), end(words), reg);
        PrintVector(words);
    }
}
