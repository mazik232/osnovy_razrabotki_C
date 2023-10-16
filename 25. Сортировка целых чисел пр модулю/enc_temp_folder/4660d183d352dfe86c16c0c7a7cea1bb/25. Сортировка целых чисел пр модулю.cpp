#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintNum(const vector<int>& x) {
    for (auto& i : x) {
        cout << i << " ";
    }
}

int main()
{
    int N;
    cin >> N;
    if (N >= 0 && N <= 1000) {
        vector<int> nums(N);
        for (auto& i : nums) {
            cin >> i; 
        }
        sort(begin(nums), end(nums), [](int a, int b) {return a < abs(b);});
        PrintNum(nums);
    }
    else {
        return 0;
    }
}
