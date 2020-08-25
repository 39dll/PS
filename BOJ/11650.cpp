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
		scanf("%d %d", &a, &b);
		vec.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", vec[i].first, vec[i].second);
	}
	return 0;
}