#include <iostream>
#include <vector>
using namespace std;
vector<int> edge[100001];//index��° ��忡�� vector�� ���� ��忡 �����
int par[100001] = { 0 }; //index��° ����� �θ�
int N, temp1, temp2;
void find(int ind) { //ind�� �ڽ��� ã�� ind�� �θ�� ����
	for (int i = 0; i < edge[ind].size(); i++) {
		if (par[edge[ind][i]] == 0) {
			par[edge[ind][i]] = ind;
			find(edge[ind][i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> temp1 >> temp2;
		edge[temp1].push_back(temp2);
		edge[temp2].push_back(temp1);
	}
	find(1);
	for (int i = 2; i <= N; i++) {
		cout << par[i] << "\n";
	}
}