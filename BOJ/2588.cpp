#include <iostream>
using namespace std;
int main() {
	int a, b, b1, b2, b3;
	cin >> a >> b;
	b1 = b % 10;
	b2 = b % 100 - b1;
	b3 = b - b2 - b1;
	cout << a * b1 << endl << a * b2 / 10 << endl << a * b3 / 100 << endl << a * b;
	return 0;
}