#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const long long INF = 2100000000;
const long long MAX_SIZE = 100001;
long long tree[MAX_SIZE * 3], h[100001]; //tree[N]의 자식은 tree[2*N], tree[2*N+1]
long long N, depth, ans, st;

long long query(long long start, long long end) {
	long long mn = INF, ret = 0;
	if (start == end)return tree[start];
	while (start <= end) {
		if (start % 2 == 1) {
			if (mn > h[tree[start]]) {
				ret = tree[start];
			}
			mn = min(mn, h[tree[start]]);
		}
		if (end % 2 == 0) {
			if (mn > h[tree[end]]) {
				ret = tree[end];
			}
			mn = min(mn, h[tree[end]]);
		}
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return ret;
}

void search(long long start, long long end) {
	if (start > end) return;
	long long minInd = query(st + start, st + end);
	ans = max(ans, h[minInd] * (end - start + 1));
	if (start == end) return;
	search(start, minInd - 1);
	search(minInd + 1, end);
}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> N;
		if (N == 0) break;
		//초기화
		for (int i = 0; i < MAX_SIZE * 3; i++)tree[i] = i;
		for (int i = 0; i < 100001; i++)h[i] = 0;
		ans = 0;

		for (int i = 1; i <= N; i++)cin >> h[i];

		//전처리
		for (int i = 1; i <= 10000; i++) {
			if (N <= (long long)pow(2, i - 1)) {
				depth = i; break;
			}
		}
		st = (long long)pow(2, depth - 1) - 1; //tree[i + st]에 실제 값들이 있음

		for (int i = 1; i <= (int)pow(2, depth - 1); i++)tree[st + i] = i;

		//세그먼트 트리 갱신
		for (int i = depth - 1; i >= 1; i--) {
			for (int j = 0; j < pow(2, i - 1); j++) {
				long long ind = pow(2, i - 1) + j;
				tree[ind] = h[tree[ind * 2]] < h[tree[ind * 2 + 1]] ? tree[ind * 2] : tree[ind * 2 + 1];
			}
		}
		
		search(1, N);

		cout << ans << '\n';
	}
}