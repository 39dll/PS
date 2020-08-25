#include <iostream>
#include <algorithm>
using namespace std;
int N, A[500001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	cout << A[N - 1];
}