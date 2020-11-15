struct SegTree {
   int sz, st, dep;
   vector<long long> pw2, v;

   SegTree(int size) {
      long long k = 1;
      for (int i = 0; i < 30; i++) {
         pw2.push_back(k); k <<= 1;
      }
      sz = size;
      v.resize(sz * 4, 0);
      dep = 1;
      while(1) {
         if (sz <= pw2[dep - 1])break;
         dep++;
      }
      st = pw2[dep - 1] - 1;
   }
   void init(long long val) {
      for (int i = 1; i < 4 * sz; i++) {
         v[i] = val;
      }
   }
   long long val(int ind) {
      return v[st + ind];
   }
   void update(int ind, long long val) {
      v[st + ind] = val;
      ind = (ind + 1) / 2;
      for (int i = dep - 1; i >= 1; i--) {
         int cur = pw2[i - 1] - 1 + ind;
         v[cur] = v[cur * 2] + v[cur * 2 + 1];
         ind = (ind + 1) / 2;
      }
   }
   long long query(int start, int end) {
      long long ret = 0;
      start += st; end += st;
      while (start <= end) {
         if (start % 2 == 1)ret += v[start];
         if (end % 2 == 0)ret += v[end];
         start = (start + 1) / 2;
         end = (end - 1) / 2;
      }
      return ret;
   }
   int kth(long long val) {
      int ptr = 1;
      while (ptr <= st) {
         if (val <= v[ptr * 2]) {
            ptr <<= 1;
         }
         else {
            val -= v[ptr * 2];
            ptr = ptr * 2 + 1;
         }
      }
      ptr -= st;
      return ptr;
   }
};
