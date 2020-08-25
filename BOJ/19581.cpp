#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p; //연결된 노드, 거리
vector<p> edge[100001];//index번째 노드에서 vector값 안의 노드에 연결됨
int dis[100001];
int mx = 0, mxind = 0;
int n, temp1, temp2, temp3;
int mx2, mx3, point1, point2;
void find(int ind, int num) {
	for (int i = 0; i < edge[ind].size(); i++) {
		int next = edge[ind][i].first;
		int cost = edge[ind][i].second;
		if (num == 1 && next == point1) continue;
		if (num == 2 && next == point2) continue;
		if (dis[next] == -1) {
			dis[next] = dis[ind] + cost;
			if (dis[next] > mx) {
				mx = dis[next];
				mxind = next;
			}
			find(next, num);
		}
	}
	if (num == 1)mx2 = mx;
	if (num == 2)mx3 = mx;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dis[i] = -1;
		cin >> temp1 >> temp2 >> temp3;
		edge[temp1].push_back({ temp2, temp3 });
		edge[temp2].push_back({ temp1, temp3 });
	}
	dis[1] = 0;
	find(1, 0);
	point1 = mxind;
	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
	}
	dis[mxind] = 0; mx = 0;
	find(mxind, 0);
	point2 = mxind;

	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
	} mx = 0;
	if (point1 == 1) {
		dis[2] = 0;
		find(2, 1);
		for (int i = 1; i <= n; i++) {
			dis[i] = -1;
		} mx = 0; dis[mxind] = 0;
		find(mxind, 1);
	}
	else {
		dis[1] = 0;
		find(1, 1);
		for (int i = 1; i <= n; i++) {
			dis[i] = -1;
		} mx = 0; dis[mxind] = 0;
		find(mxind, 1);
	}

	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
	} mx = 0;
	if (point2 == 1) {
		dis[2] = 0;
		find(2, 2);
		for (int i = 1; i <= n; i++) {
			dis[i] = -1;
		} mx = 0; dis[mxind] = 0;
		find(mxind, 2);
	}
	else {
		dis[1] = 0;
		find(1, 2);
		for (int i = 1; i <= n; i++) {
			dis[i] = -1;
		} mx = 0; dis[mxind] = 0;
		find(mxind, 2);
	}
	cout << max(mx2, mx3);
}