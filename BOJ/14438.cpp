#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const long long INF = 2100000000;
const long long MAX_SIZE = 100001;
long long tree[MAX_SIZE * 3]; //tree[N]의 자식은 tree[2*N], tree[2*N+1]
long long N, M, depth;

long long query(long long start, long long end) {
	long long ret = INF;
	while (start <= end) {
		if (start % 2 == 1) {
			ret = min(ret, tree[start]);
		}
		if (end % 2 == 0) {
			ret = min(ret, tree[end]);
		}
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	//초기화
	for (int i = 0; i < MAX_SIZE * 3; i++)tree[i] = INF;

	//수의 개수, 쿼리의 개수
	cin >> N;

	//전처리
	for (int i = 1; i <= 10000; i++) {
		if (N <= (long long)pow(2, i - 1)) {
			depth = i; break;
		}
	}
	long long st = (long long)pow(2, depth - 1) - 1; //tree[i + st]에 실제 값들이 있음

													 //숫자 입력
	for (int i = 1; i <= N; i++) {
		cin >> tree[i + st];
	}

	//세그먼트 트리 갱신
	for (int i = depth - 1; i >= 1; i--) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			long long ind = pow(2, i - 1) + j;
			tree[ind] = min(tree[ind * 2], tree[ind * 2 + 1]);
		}
	}
	cin >> M;

	//쿼리 처리
	for (int i = 0; i < M; i++) {
		long long in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		if (in1 == 1) {
			tree[st + in2] = in3;
			in2 = (in2 + 1) / 2;
			for (int i = depth - 1; i >= 1; i--) {
				long long ind = pow(2, i - 1) + in2 - 1;
				tree[ind] = min(tree[ind * 2], tree[ind * 2 + 1]);
				in2 = (in2 + 1) / 2;
			}
		}
		if (in1 == 2)cout << query(st + in2, st + in3) << '\n';
	}
}