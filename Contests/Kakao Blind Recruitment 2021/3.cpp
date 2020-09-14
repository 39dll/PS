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

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> ans;
    vector<tuple<string, string, string, string, int>> ppl;
    vector<int> v[3][2][2][2];
    for(int i=0;i<info.size();i++){
        string infor[4];
        int info5;
        string curstr = "";
        int segment = 0;
        for(int j=0;j<info[i].size();j++){
            if(info[i][j]!=' ')curstr+=info[i][j];
            else{
                infor[segment]=curstr;
                curstr.clear();
                segment++;
            }
        }
        info5 = mystoi(curstr);
        ppl.push_back({infor[0],infor[1],infor[2],infor[3],info5});
        if(infor[0]=="cpp"){
            if(infor[1]=="backend"){
                if(infor[2]=="junior"){
                    if(infor[3]=="chicken"){
                        v[0][0][0][0].push_back(info5);
                    }
                    else{
                        v[0][0][0][1].push_back(info5);
                    }
                }
                else{
                    if(infor[3]=="chicken"){
                        v[0][0][1][0].push_back(info5);
                    }
                    else{
                        v[0][0][1][1].push_back(info5);
                    }
                }
            }
            else{
                if(infor[2]=="junior"){
                    if(infor[3]=="chicken"){
                        v[0][1][0][0].push_back(info5);
                    }
                    else{
                        v[0][1][0][1].push_back(info5);
                    }
                }
                else{
                    if(infor[3]=="chicken"){
                        v[0][1][1][0].push_back(info5);
                    }
                    else{
                        v[0][1][1][1].push_back(info5);
                    }
                }
            }
        }
        else if(infor[0]=="java"){
            if(infor[1]=="backend"){
                if(infor[2]=="junior"){
                    if(infor[3]=="chicken"){
                        v[1][0][0][0].push_back(info5);
                    }
                    else{
                        v[1][0][0][1].push_back(info5);
                    }
                }
                else{
                    if(infor[3]=="chicken"){
                        v[1][0][1][0].push_back(info5);
                    }
                    else{
                        v[1][0][1][1].push_back(info5);
                    }
                }
            }
            else{
                if(infor[2]=="junior"){
                    if(infor[3]=="chicken"){
                        v[1][1][0][0].push_back(info5);
                    }
                    else{
                        v[1][1][0][1].push_back(info5);
                    }
                }
                else{
                    if(infor[3]=="chicken"){
                        v[1][1][1][0].push_back(info5);
                    }
                    else{
                        v[1][1][1][1].push_back(info5);
                    }
                }
            }
        }
        else{
            if(infor[1]=="backend"){
                if(infor[2]=="junior"){
                    if(infor[3]=="chicken"){
                        v[2][0][0][0].push_back(info5);
                    }
                    else{
                        v[2][0][0][1].push_back(info5);
                    }
                }
                else{
                    if(infor[3]=="chicken"){
                        v[2][0][1][0].push_back(info5);
                    }
                    else{
                        v[2][0][1][1].push_back(info5);
                    }
                }
            }
            else{
                if(infor[2]=="junior"){
                    if(infor[3]=="chicken"){
                        v[2][1][0][0].push_back(info5);
                    }
                    else{
                        v[2][1][0][1].push_back(info5);
                    }
                }
                else{
                    if(infor[3]=="chicken"){
                        v[2][1][1][0].push_back(info5);
                    }
                    else{
                        v[2][1][1][1].push_back(info5);
                    }
                }
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    sort(v[i][j][k][l].begin(),v[i][j][k][l].end());
                }
            }
        }
    }
    
    
    for(int i=0;i<query.size();i++){
        int segment = 0;
        string qr[4];
        int sc;
        string curstr = "";
        for(int j=0;j<query[i].size();j++){
            if(query[i][j]!=' '){
                curstr+=query[i][j];
            }
            else{
                if(segment%2==1){
                    curstr.clear();
                    segment++;
                }
                else{
                    qr[segment/2]=curstr;
                    curstr.clear();
                    segment++;
                }
            }
        }
        sc = mystoi(curstr);
        int cnt = 0;
        
        int ist, iend, jst, jend, kst, kend, lst, lend;
        
        if(qr[0]=="-"){
            ist=0; iend=2;
        }
        else if(qr[0]=="cpp"){
            ist=iend=0;
        }
        else if(qr[0]=="java"){
            ist=iend=1;
        }
        else{
            ist=iend=2;
        }
        if(qr[1]=="-"){
            jst=0;jend=1;
        }
        else if(qr[1]=="backend"){
            jst=jend=0;
        }
        else{
            jst=jend=1;
        }
        if(qr[2]=="-"){
            kst=0;kend=1;
        }
        else if(qr[2]=="junior"){
            kst=kend=0;
        }
        else{
            kst=kend=1;
        }
        if(qr[3]=="-"){
            lst=0;lend=1;
        }
        else if(qr[3]=="chicken"){
            lst=lend=0;
        }
        else{
            lst=lend=1;
        }
        for(int i=ist;i<=iend;i++){
                for(int j=jst;j<=jend;j++){
                    for(int k=kst;k<=kend;k++){
                        for(int l=lst;l<=lend;l++){
                            int it = lower_bound(v[i][j][k][l].begin(),v[i][j][k][l].end(),sc) - v[i][j][k][l].begin();
                            cnt+=v[i][j][k][l].size()-it;
                        }
                    }
                }
            }
        
        ans.push_back(cnt);
    }
    return ans;
}