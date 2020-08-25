#include <iostream>
#include <cmath>
using namespace std;
long long tree[5000000] = { 0 }; //tree[N]의 자식은 tree[2*N], tree[2*N+1]
long long N, M, K, depth, com, temp1, temp2;
long long add(long long start, long long end) {
	long long ret = 0;
	while (start <= end) {
		if (start % 2 == 1) ret += tree[start];
		if (end % 2 == 0) ret += tree[end];
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
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
			tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
		}
	}
	for (int ii = 0; ii < M + K; ii++) {
		cin >> com >> temp1 >> temp2;
		if (com == 1) {
			long long minus = tree[(long long)pow(2, depth - 1) + temp1 - 1] - temp2;
			for (int i = depth; i >= 1; i--) {
				tree[(long long)pow(2, i - 1) + temp1 - 1] -= minus;
				temp1 = temp1 / 2 + (temp1 % 2 == 1);
			}
		}
		else if (com == 2) {
			cout << add(temp1 + (long long)pow(2, depth - 1) - 1, temp2 + (long long)pow(2, depth - 1) - 1) << "\n";
		}
	}
}