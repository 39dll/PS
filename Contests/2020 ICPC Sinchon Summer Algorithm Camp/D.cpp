#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int X, Y, M, curM;
vector<int> ans;
priority_queue<p> pq;
priority_queue<p, vector<p>, greater<p>> pq2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> X >> Y >> M;
	int in;
	for (int i = 0; i < X; i++) {
		cin >> in;
		pq.push({ in,i + 1 });
	}
	for (int i = 0; i < Y; i++) {
		cin >> in;
		pq2.push({ in,i + 1 });
	}
	curM = M;
	while (!pq.empty()) {
		int cur = pq.top().first;
		int curind = pq.top().second;
		pq.pop();
		if (curM <= cur) {
			while (1) {
				if (curM > cur)break;
				if (pq2.empty()) {
					cout << 0;
					return 0;
				}
				curM = min(M, curM + pq2.top().first);
				ans.push_back(pq2.top().second);
				pq2.pop();
			}
		}
		curM -= cur;
		ans.push_back(-curind);
		continue;
	}
	while (!pq2.empty()) {
		ans.push_back(pq2.top().second);
		pq2.pop();
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}
