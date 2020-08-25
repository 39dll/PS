#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A[100001], num, res = 0;
void calc(int start, int end) {
	int mid = (start + end) / 2;
	if (num == A[mid]) { res = 1; return; }
	if ((end - start) % 2 == 1 && num == A[mid + 1]) { res = 1; return; }
	if (start == mid || end == mid) return;
	if (num > A[mid]) { calc(mid, end); }
	else { calc(start, mid); }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	cin >> M;
	while (M--) {
		cin >> num;
		calc(0, N-1);
		cout << res << "\n";
		res = 0;
	}
}