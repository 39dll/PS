struct lazy {
	struct fenwick {
		long long sz;
		long long *arr;
		fenwick(int size) {
			sz = size + 1;
			arr = new long long[sz];
			fill(arr, arr + sz, 0);
		}
		void update(int i, long long x) {
			while (i < sz) {
				arr[i] += x;
				i += i & -i;
			}
		}
		long long sum(int i) const {
			long long x = 0;
			while (i) {
				x += arr[i];
				i -= i & -i;
			}
			return x;
		}
	};
	fenwick *suma, *sumb;
	lazy(int size) {
		suma = new fenwick(size);
		sumb = new fenwick(size);
	}
	void add(int L, int R, long long val) {
		suma->update(L, val);
		suma->update(R + 1, -val);
		sumb->update(L, (1LL - L)*val);
		sumb->update(R + 1, 1LL * R*val);
	}
	long long query(int L, int R) {
		long long ans = 0;
		ans += suma->sum(R)*R + sumb->sum(R);
		ans -= suma->sum(L - 1)*(L - 1) + sumb->sum(L - 1);
		return ans;
	}
};
