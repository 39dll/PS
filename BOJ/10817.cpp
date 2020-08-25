#include <iostream>
using namespace std;

int main() {
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	if (a1 >= a2&&a2 >= a3) {
		cout << a2;
	}
	else if (a1 >= a3&&a3 >= a2) {
		cout << a3;
	}
	else if (a2 >= a3&&a3 >= a1) {
		cout << a3;
	}
	else if (a2 >= a1&&a1 >= a3) {
		cout << a1;
	}
	else if (a3 >= a1&&a1 >= a2) {
		cout << a1;
	}
	else if (a3 >= a2&&a2 >= a1) {
		cout << a2;
	}
	return 0;
}