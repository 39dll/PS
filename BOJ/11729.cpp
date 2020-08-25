#include <iostream>
#include <cmath>
using namespace std;
void move(int A, int B) {
	cout << A << " " << B << "\n";
}
void hanoi(int n, int A, int B, int C) {
	if (n == 1) {
		move(A, C); return;
	}
	hanoi(n - 1, A, C, B);
	hanoi(1, A, B, C);
	hanoi(n - 1, B, A, C);
}
int main(){
	int K;
	long a;
	cin >> K;
	a = pow(2, K) - 1;
	cout << a << "\n";
	hanoi(K, 1, 2, 3);
}