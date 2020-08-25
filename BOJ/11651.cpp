#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int N, a, b;
	scanf("%d", &N);
	vector<pair <int,int> > vec;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &b, &a);
		vec.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", vec[i].second, vec[i].first);
	}
	return 0;
}