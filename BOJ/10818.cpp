#include <iostream>
using namespace std;
int max(int arg0, int arg1) { if (arg0 > arg1) return arg0; else return arg1; }
int min(int arg0, int arg1) { if (arg0 < arg1) return arg0; else return arg1; }
int main() {
	int N, Max, Min;
	cin >> N;
	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	Max = a[0]; Min = a[0];
	for (int i = 0; i < N-1; i++) {
		Max = max(Max, a[i + 1]);
		Min = min(Min, a[i + 1]);
	}
	cout << Min << " " << Max;
	return 0;
}