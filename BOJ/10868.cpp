#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long tree[300001]; //tree[N]의 자식은 tree[2*N], tree[2*N+1]
long long N, M, depth, com, temp1, temp2;
long long printmin(long long start, long long end) {
	long long ret = 2100000000;
	while (start <= end) {
		if (start % 2 == 1) ret = min(ret, tree[start]);
		if (end % 2 == 0) ret = min(ret, tree[end]);
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i <= 300000; i++)tree[i] = 2100000000;
	cin >> N >> M;
	for (int i = 1; i <= 30; i++) {
		if (N <= pow(2, i - 1)) {
			depth = i; break;
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> tree[i + (long long)pow(2, depth - 1) - 1];
	}
	for (int i = depth - 1; i >= 1; i--) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			long long ind = pow(2, i - 1) + j;
			tree[ind] = min({ tree[ind], tree[ind * 2], tree[ind * 2 + 1] });
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> temp1 >> temp2;
		cout << printmin((long long)pow(2, depth - 1) - 1 + temp1, (long long)pow(2, depth - 1) - 1 + temp2) << '\n';
	}
}