#include <iostream>
using namespace std;
int max(int arg0, int arg1) { if (arg0 > arg1) return arg0; else return arg1; }
int main() {
	int Max, N = 1;
	int *a = new int[9];
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	Max = a[0];
	for (int i = 0; i < 8; i++) {
		if (Max < a[i + 1]) N = i + 2;
		Max = max(Max, a[i + 1]);
	}
	cout << Max << "\n" << N;
	return 0;
}