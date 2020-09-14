#include <bits/stdc++.h>

using namespace std;
int mystoi(string str){
	int len = str.length();
	int sum = 0;
	for (int i = len - 1, p = 1; i >= 0;  i--, p *= 10) {
		str[i] -= '0'; 
		sum += str[i] * p;
	}
	return sum;
}
int parsetime(string str){
    int out = 0;
    out += 36000 * (str[0]-'0');
    out += 3600 * (str[1]-'0');
    out += 600 * (str[3]-'0');
    out += 60 * (str[4]-'0');
    out += 10 * (str[6]-'0');
    out += (str[7]-'0');
    return out;
}
string maketime(int t){
    string out = "";
    out.push_back(t/36000+'0');
    t %= 36000;
    out.push_back(t/3600+'0');
    t %= 3600;
    out.push_back(':');
    out.push_back(t/600+'0');
    t %= 600;
    out.push_back(t/60+'0');
    t %= 60;
    out.push_back(':');
    out.push_back(t/10+'0');
    t %= 10;
    out.push_back(t+'0');
    return out;
}


string solution(string play_time, string adv_time, vector<string> logs) {
    int playtime = parsetime(play_time);
    int advtime = parsetime(adv_time);
    long long lol[3600001] = {0};
    vector<int> st, en;
    for(int i=0;i<logs.size();i++){
        string t1 = logs[i].substr(0,8);
        string t2 = logs[i].substr(9,8);
        st.push_back(parsetime(t1));
        en.push_back(parsetime(t2));
    }
    sort(st.begin(),st.end());
    sort(en.begin(),en.end());
    
    long long cur = 0;
    int ptr1 = 0, ptr2 = 0;
    
    for(int i=0;i<=playtime;i++){
        if(ptr1!=st.size()){
        if(i==st[ptr1]){
            while(i==st[ptr1]){
                ptr1++;
                cur++;
                if(ptr1==st.size())break;
            }
        }
        }
        if(ptr2!=en.size()){
        if(i>0){
            if(i==en[ptr2]){
                while(i==en[ptr2]){
                    ptr2++;
                    cur--;
                    if(ptr2==en.size())break;
                }
            }
        }
        }
        lol[i]=cur;
    }
    
    long long curplaytime = 0;
    long long maxplaytime = 0;
    int ans = 0;
    for(int i=0;i<=advtime;i++){
        curplaytime += lol[i];
    }
    maxplaytime = curplaytime;
    int beg = 0;
    int ed = advtime-1;
    while(ed < playtime){
        beg++; ed++;
        curplaytime-=lol[beg-1];
        curplaytime+=lol[ed];
        if(maxplaytime<curplaytime){
            maxplaytime=curplaytime;
            ans=beg;
        }
    }
    return maketime(ans);
}