#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

int main() {
	int a = 8;
	int b = 12;
	int x = a;
	int y = b;
	while (a > 0 && b > 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	int s = a + b;
	a = x / s;
	b = y / s;
	cout << a << "/" << b;
}