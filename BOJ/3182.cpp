#include <iostream>
#include <cstring>
using namespace std;
int N, mx, ans, arr[1001];
bool visited[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		int cur = i, cnt = 0;
		while(!visited[cur]) {
			visited[cur] = 1;
			cur = arr[cur];
			cnt++;
		}
		if (cnt > mx) {
			mx = cnt;
			ans = i;
		}
	}
	cout << ans;
}