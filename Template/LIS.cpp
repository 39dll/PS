typedef pair<int, int> p;
vector<int> lis(const vector<int> &v) {
	if (v.empty())return{};
	vector<int> prev(v.size());
	vector<p> res;
	for (int i = 0; i < v.size(); i++) {
		auto it = lower_bound(res.begin(), res.end(), p{ v[i],0 });
		if (it == res.end())res.emplace_back(), it = res.end() - 1;
		*it = { v[i],i };
		prev[i] = it == res.begin() ? 0 : (it - 1)->second;
	}
	int L = res.size(), cur = res.back().second;
	vector<int> ans(L);
	while (L--)ans[L] = cur, cur = prev[cur];
	return ans;
}
