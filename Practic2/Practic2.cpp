#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
public:
	Matrix() {
		num_rows = 0;
		num_cols = 0;
	}
	Matrix(int nums, int cols) {
		Reset(nums, cols);
	}
	void Reset(int nums, int cols) {

	}
	int At() const {

	}
	int& At() {

	}
	int GetNumRows() const {
		return num_rows;
	}
	int GetNumCols() const {
		return num_cols;
	}
private:
	int num_rows;
	int num_cols;
	vector<vector<int>> matrix;
};

bool operator==() {

}
Matrix operator+() {

}
istream operator>>() {

}
ostream operator<<() {

}
int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}