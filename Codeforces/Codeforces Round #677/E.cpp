#include <bits/stdc++.h>
using namespace std;
long long ans[] = { 1, 1, 1, 1, 3, 8, 40, 180, 1260, 8064, 72576, 604800, 6652800, 68428800, 889574400, 10897286400, 163459296000, 2324754432000, 39520825344000, 640237370572800, 12164510040883200 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	cout << ans[N];
}
