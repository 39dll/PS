#include <iostream>
using namespace std;
int main() {
	int N, X;
	cin >> N >> X;
	int *p = new int[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= N; i++) {
		if (int(p[i]) < X) {
			cout << p[i] << " ";
		}
	}
	return 0;
}