#include <bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
long long tree[MAX_SIZE * 4]; //tree[N]의 자식은 tree[2*N], tree[2*N+1]
long long N, M, depth, st;

void update(long long ind, long long val) {
	tree[st + ind] = val;
	ind = (ind + 1) / 2;
	for (int i = depth - 1; i >= 1; i--) {
		int cur = pow(2, i - 1) - 1 + ind;
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
		ind = (ind + 1) / 2;
	}
}

long long query(long long start, long long end) {
	long long ret = 0;
	start += st; end += st;
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

	//초기화
	//for (int i = 0; i < MAX_SIZE * 4; i++)tree[i] = 0;

	//수의 개수
	cin >> N;

	//전처리
	depth = 1;
	while (1) {
		if (N <= (long long)pow(2, depth - 1))break;
		depth++;
	}
	st = (long long)pow(2, depth - 1) - 1;

	//숫자 입력
	for (int i = 1; i <= N; i++) {
		cin >> tree[i + st];
	}

	//세그먼트 트리 갱신
	for (int i = depth - 1; i >= 1; i--) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			long long ind = pow(2, i - 1) + j;
			tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
		}
	}

	//쿼리의 개수
	cin >> M;

	//쿼리 처리
	for (int t = 0; t < M; t++) {
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;

		if (in1 == 1) {//set in2-nd index to in3
			update(in2, in3);
		}
		else if (in1 == 2) {//perform query for in2 ~ in3
			cout << query(in2, in3) << '\n';
		}
	}
}
