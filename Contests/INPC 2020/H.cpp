#include <bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 100001;
long long arr[MAX_SIZE];
long long tree[MAX_SIZE * 4];
long long N, M, depth, st;

long long query(long long start, long long end) {
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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	N++;
	depth = 1;
	while (1) {
		if (N <= (long long)pow(2, depth - 1))break;
		depth++;
	}
	st = (long long)pow(2, depth - 1) - 1;

	for (int i = 1; i < N; i++) {
		cin >> arr[i];
	}

	tree[1 + st] = arr[1];
	for (int i = 2; i < N; i++) {
		tree[i + st] = arr[i] - arr[i - 1];
	}

	for (int i = depth - 1; i >= 1; i--) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			long long ind = pow(2, i - 1) + j;
			tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
		}
	}

	for (int t = 0; t < M; t++) {
		int in1, in2, in3, in4;
		cin >> in2;

		cin >> in3 >> in4;
		tree[st + in2] += in4;
		in2 = (in2 + 1) / 2;
		for (int i = depth - 1; i >= 1; i--) {
			int ind = pow(2, i - 1) - 1 + in2;
			tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
			in2 = (in2 + 1) / 2;
		}
		in3++;
		tree[st + in3] -= in4;
		in3 = (in3 + 1) / 2;
		for (int i = depth - 1; i >= 1; i--) {
			int ind = pow(2, i - 1) - 1 + in3;
			tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
			in3 = (in3 + 1) / 2;
		}
	}
	for (int i = 1; i < N; i++) {
		cout << query(st + 1, st + i) << ' ';
	}
}
