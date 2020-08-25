#include <iostream>
using namespace std;
int main() {
	int L, P, temp;
	cin >> L >> P;
	L *= P;
	for (int i = 0; i <= 4; i++) {
		cin >> temp;
		cout << temp - L << " ";
	}
}