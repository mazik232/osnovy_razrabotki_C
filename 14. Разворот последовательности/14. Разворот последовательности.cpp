#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Reverse(vector<int>& numbers) {
    int bufer = 0;
    for (int x = 0; x < numbers.size()/ 2; x++) {
        bufer = numbers[numbers.size()- x - 1];
        numbers[numbers.size() - x -1] = numbers[x];
        numbers[x] = bufer;
    }
}
int main()
{
    vector<int> a = { 1, 5, 3, 4, 2};
    Reverse(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}
