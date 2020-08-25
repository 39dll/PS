#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int ii = 1; ii <= i; ii++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}