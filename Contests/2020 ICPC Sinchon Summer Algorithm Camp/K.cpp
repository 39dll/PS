#include <bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 200001;
long long tree[MAX_SIZE * 3];
long long N, depth, st;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= 10000; i++) {
		if (N <= (long long)pow(2, i - 1)) {
			depth = i; break;
		}
	}
	st = (long long)pow(2, depth - 1) - 1;
	for (int i = 1; i <= N; i++) {
		cin >> tree[i + st];
	}
	for (int i = depth - 1; i >= 1; i--) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			long long ind = pow(2, i - 1) + j;
			tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
		}
	}
	for (int i = 0; i < N; i++) {
		long long in, ptr = 1;
		cin >> in;
		while (ptr <= st) {
			if (in <= tree[ptr * 2]) {
				ptr *= 2;
			}
			else {
				in -= tree[ptr * 2];
				ptr = ptr * 2 + 1;
			}
		}
		ptr -= st;
		cout << ptr << ' ';
		long long minus = tree[st + ptr];
		for (int i = depth; i >= 1; i--) {
			tree[(long long)pow(2, i - 1) - 1 + ptr] -= minus;
			ptr = (ptr + 1) / 2;
		}
	}
}
