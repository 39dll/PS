#include <bits/stdc++.h>
using namespace std;
int N, M, arr[10001], ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = i; j <= N; j++) {
			temp += arr[j];
			if (temp == M)ans++;
			if (temp > M)break;
		}
	}
	cout << ans;
}