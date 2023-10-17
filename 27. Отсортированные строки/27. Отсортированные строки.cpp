#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        words.push_back(s);
        // добавить строку s в набор
    }
    vector<string> GetSortedStrings() {
        sort(begin(words), end(words));
        return words;
        // получить набор из всех добавленных строк в отсортированном порядке
    }
private:
    vector<string> words;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);
}
