#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class ReversibleString 
{
public:
    ReversibleString(){}
    ReversibleString(const string r_word)
    {
        word = r_word;
    }
    void Reverse() {
        reverse(begin(word), end(word));
    }
    string ToString() const {
        return word;
    }
private:
    string word;
};




int main()
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;

}

