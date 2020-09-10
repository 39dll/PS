#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
struct point {
	int x, y;//실제 위치
	int p, q;//기준점으로부터 상대 위치
	point() : point(0, 0, 1, 0) {}
	point(int x1, int y1) :point(x1, y1, 1, 0) {}
	point(int x1, int y1, int p1, int q1) :x(x1), y(y1), p(p1), q(q1) {}
	bool operator<(const point& O) {
		if (1LL * q*O.p != 1LL * p*O.q)return 1LL * q*O.p < 1LL * p*O.q;
		if (y != O.y)return y < O.y;
		return x < O.x;
	}
};
long long ccw(const point& A, const point& B, const point& C) {
	return 1LL * (B.x - A.x)*(C.y - A.y) - 1LL * (B.y - A.y)*(C.x - A.x);
}
point p[MAX];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		p[i] = point(in1, in2);
	}
	sort(p, p + N);
	for (int i = 1; i < N; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p + 1, p + N);//반시계 방향 정렬
	stack<int> cvh;
	cvh.push(0); cvh.push(1);
	int next = 2;
	while (next < N) {
		while (cvh.size() >= 2) {
			int fst, scd;
			fst = cvh.top();
			cvh.pop();
			scd = cvh.top();
			if (ccw(p[scd], p[fst], p[next]) > 0) {
				cvh.push(fst);
				break;
			}
		}
		cvh.push(next++);
	}
	cout << cvh.size();
}
