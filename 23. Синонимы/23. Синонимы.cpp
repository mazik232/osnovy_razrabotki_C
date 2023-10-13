#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string, set<string>> a;
    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            a[word1].insert(word2);
        }
        else if (command == "COUNT") {
            string word;
            int value = 0;
            cin >> word;
            for (auto& x : a) {
                if (word == x.first || x.second.count(word)) {
                    value++;
                }
            }
            cout << value << endl;
        }
        else if (command == "CHECK") {
            string word1, word2;
            set<string> words;
            cin >> word1 >> word2;
            if ((a.count(word1) && a[word1].count(word2)) || (a.count(word2) && a[word2].count(word1))) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }

}
