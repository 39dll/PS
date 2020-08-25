#include <iostream>
#include <vector>
using namespace std;
int N, M, in1, in2;
bool corona[100001];
bool ans[100001];
bool temp[100001];
bool inf;
vector<int> moim[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> in1;
		for (int j = 0; j < in1; j++) {
			cin >> in2;
			moim[i].push_back(in2);
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> corona[i];
		ans[i] = corona[i];
	}
	for (int i = M - 1; i >= 0; i--) {
		int sum = 0;
		for (int j = 0; j < moim[i].size(); j++) {
			sum += ans[moim[i][j]];
		}
		if (sum == moim[i].size()) continue;
		for (int j = 0; j < moim[i].size(); j++) {
			ans[moim[i][j]] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		temp[i] = ans[i];
	}
	for (int i = 0; i < M; i++) {
		inf = 0;
		for (int j = 0; j < moim[i].size(); j++) {
			if (temp[moim[i][j]] == 1) {
				inf = 1;
				break;
			}
		}
		if (inf == 1) {
			for (int j = 0; j < moim[i].size(); j++) {
				temp[moim[i][j]] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (temp[i] == corona[i]) continue;
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
}