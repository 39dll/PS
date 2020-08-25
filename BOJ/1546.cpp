#include <iostream>
using namespace std;
int max(int arg0, int arg1) { if (arg0 > arg1)return arg0; else return arg1; }
int main() {
	int N, M = 0;
	double S = 0;
	cin >> N;
	int *a = new int[N];
	double *b = new double[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		M = max(M, a[i]);
	}
	for (int i = 0; i < N; i++) {
		b[i] = a[i];
		b[i] /= M;
		b[i] *= 100;
		S += b[i];
	}
	S /= N;
	cout << S;
	return 0;
}