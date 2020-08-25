#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<long long, long long> p;
const long long INF = 2100000000;
const long long MAX_SIZE = 100001;
p tree[MAX_SIZE * 3]; //tree[N]의 자식은 tree[2*N], tree[2*N+1]
long long N, M, depth;

long long getSecond(long long a, long long b, long long c, long long d) {
	long long temp[] = { a,b,c,d };
	sort(temp, temp + 4);
	return temp[2];
}

long long query(long long start, long long end) {
	long long ret = 0, ret2 = 0;
	while (start <= end) {
		if (start % 2 == 1) {
			ret2 = getSecond(ret, ret2, tree[start].first, tree[start].second);
			ret = max(ret, tree[start].first);
		}
		if (end % 2 == 0) {
			ret2 = getSecond(ret, ret2, tree[end].first, tree[end].second);
			ret = max(ret, tree[end].first);
		}
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return ret + ret2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	//초기화
	for (int i = 0; i < MAX_SIZE * 3; i++)tree[i] = { 0,0 };

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
		long long in;
		cin >> in;
		tree[i + st].first = in;
	}

	//세그먼트 트리 갱신
	for (int i = depth - 1; i >= 1; i--) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			long long ind = pow(2, i - 1) + j;
			tree[ind].first = max({ tree[ind * 2].first, tree[ind * 2].second, tree[ind * 2 + 1].first, tree[ind * 2 + 1].second });
			tree[ind].second = getSecond(tree[ind * 2].first, tree[ind * 2].second, tree[ind * 2 + 1].first, tree[ind * 2 + 1].second);
		}
	}
	cin >> M;

	//쿼리 처리
	for (int i = 0; i < M; i++) {
		long long in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		if (in1 == 1) {
			tree[st + in2].first = in3;
			in2 = (in2 + 1) / 2;
			for (int i = depth - 1; i >= 1; i--) {
				long long ind = pow(2, i - 1) + in2 - 1;
				tree[ind].first = max({ tree[ind * 2].first, tree[ind * 2].second, tree[ind * 2 + 1].first, tree[ind * 2 + 1].second });
				tree[ind].second = getSecond(tree[ind * 2].first, tree[ind * 2].second, tree[ind * 2 + 1].first, tree[ind * 2 + 1].second);
				in2 = (in2 + 1) / 2;
			}
		}
		if (in1 == 2)cout << query(st + in2, st + in3) << '\n';
	}
}