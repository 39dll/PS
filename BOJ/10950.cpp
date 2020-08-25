#include <iostream>
using namespace std;
int main() {
	int a[10000] = { 0, }, b[10000] = { 0, }, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a[i] >> b[i];
	}
	for (int ii = 0; ii < t; ii++) {
		cout << a[ii] + b[ii] << endl;
	}
	return 0;
}