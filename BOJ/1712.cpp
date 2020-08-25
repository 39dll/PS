#include <iostream>
using namespace std;
int main() {
	int A, B, C, Q;
	cin >> A >> B >> C;
	if (C - B > 0) {
		Q = A / (C - B) + 1;
	}
	else Q = -1;
	cout << Q;
	return 0;
}