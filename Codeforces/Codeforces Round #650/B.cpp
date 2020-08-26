#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		int N, incodd = 0, inceven = 0;
		cin >> N;
		for (int i = 0; i < N; i++)cin >> arr[i];
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0 && arr[i] % 2 != 0)inceven++;
			if (i % 2 == 1 && arr[i] % 2 != 1)incodd++;
		}
		if (incodd == inceven)cout << incodd << '\n';
		else cout << -1 << '\n';
	}
}
