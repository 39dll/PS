#include <bits/stdc++.h>
using namespace std;

long long solution(string s) {
    long long ans = 0;
    for(long long i=0;i<s.length();i++){
        for(long long j=i;j<s.length();j++){
            long long cur = 0;
            for(long long k = i;k < j;k++){
                for(long long l = i + 1;l <= j;l++){
                    if(s[k]!=s[l]){
                        cur = max(cur, l - k);
                    }
                }
            }
            ans += cur;
        }
    }
    return ans;
}
