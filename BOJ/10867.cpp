#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> v;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
}