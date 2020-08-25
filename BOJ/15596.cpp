#include <vector>
long long sum(std::vector<int> &a){
	long long c;
	for (int i = 0; i < a.size(); i++) {
		c += a[i];
	}
	return c;
}