#include <iostream>
using namespace std;
int compare(int x1, int y1, int x2, int y2) {
	if (x1 > x2 && y1 > y2) return 1;
	else if (x2 > x1 && y2 > y1) return 2;
	else return 0;
}
int min(int a, int b) { if (a < b) return a; else return b; }
int main() {
	int N, k, m;
	cin >> N;
	int *x = new int[N];
	int *y = new int[N];
	int *q = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		q[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (x[i] > x[j] && y[i] > y[j]) q[j]++;
		}
	}
	for (int i = 0; i < N; i++) cout << q[i] << " ";
	return 0;
}