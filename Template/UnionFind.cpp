struct UF {
    vector<int> uf;
    UF(int sz) {
        uf.resize(sz + 1);
        for(int i = 0; i < sz + 1; i++) {
            uf[i] = i;
        }
    }
    int find(int ind) {
        if(ind == uf[ind]) return ind;
        return uf[ind] = find(uf[ind]);
    }
    void merge(int ind1, int ind2) {
        ind1 = find(ind1), ind2 = find(ind2);
        if (ind1 != ind2)uf[ind2] = ind1;
    }
};
