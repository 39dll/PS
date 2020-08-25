#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int A, B, C;
	unsigned int M;
	unsigned int *p = new unsigned int[9];
	int *q = new int[9];
	cin >> A >> B >> C;
	M = A * B * C;
	p[0] = M % int(pow(10, 1));
	p[1] = (M - p[0]) % int(pow(10, 2));
	p[2] = (M - p[0] - p[1]) % int(pow(10, 3));
	p[3] = (M - p[0] - p[1] - p[2]) % int(pow(10, 4));
	p[4] = (M - p[0] - p[1] - p[2] - p[3]) % int(pow(10, 5));
	p[5] = (M - p[0] - p[1] - p[2] - p[3] - p[4]) % int(pow(10, 6));
	p[6] = (M - p[0] - p[1] - p[2] - p[3] - p[4] - p[5]) % int(pow(10, 7));
	p[7] = (M - p[0] - p[1] - p[2] - p[3] - p[4] - p[5] - p[6]) % int(pow(10, 8));
	p[8] = (M - p[0] - p[1] - p[2] - p[3] - p[4] - p[5] - p[6] - p[7]) % int(pow(10, 9));
	p[9] = (M - p[0] - p[1] - p[2] - p[3] - p[4] - p[5] - p[6] - p[7] - p[8]) % int(pow(10, 10));
	for (int i = 0; i < 10; i++) {
		p[i] /= pow(10, i);
		q[i] = 0;
	}
	for (int i = 9; i >= 0; i--) {
		if (M < pow(10, i)) {
			p[i] = 11;
		}
	}
	for (int i = 0; i <= 9; i++) {
		if (p[i] != 11) {
			q[9 - p[i]]++;
		}
	}
	for (int i = 0; i <= 9; i++) {
		cout << q[9 - i] << "\n";
	}
	
	return 0;
}