#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A[500001], num, res = 0, ind0, ind1;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	cin >> M;
	while (M--) {
		cin >> num;
		cout << min(1LL, (long long)(upper_bound(A, A + N, num) - lower_bound(A, A + N, num))) << " ";
	}
}