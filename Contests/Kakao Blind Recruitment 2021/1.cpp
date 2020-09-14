#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>='A'&&new_id[i]<='Z'){
            new_id[i] = new_id[i] - 'A' + 'a';
        }
    }
    string newstr = "";
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>='a'&&new_id[i]<='z')newstr+=new_id[i];
        if(new_id[i]>='0'&&new_id[i]<='9')newstr+=new_id[i];
        if(new_id[i]=='_')newstr+=new_id[i];
        if(new_id[i]=='.')newstr+=new_id[i];
        if(new_id[i]=='-')newstr+=new_id[i];
    }
    string newstr2 = "";
    bool streak = 0;
    for(int i=0;i<newstr.size();i++){
        if(newstr[i]=='.'){
            if(streak==0)newstr2+=newstr[i];
            streak=1;
        }
        else{
            newstr2+=newstr[i];
            streak=0;
        }
    }
    string newstr3 = "";
    for(int i=0;i<newstr2.size();i++){
        if(i==0 && newstr2[i]=='.')continue;
        if(i==newstr2.size()-1 && newstr2[i]=='.')continue;
        newstr3 += newstr2[i];
    }
    if(newstr3=="")newstr3="a";
    if(newstr3.size()>15)newstr3.resize(15);
    if(newstr3[newstr3.size()-1]=='.')newstr3=newstr3.substr(0,newstr3.size()-1);
    if(newstr3.size()<=2){
        char last = newstr3[newstr3.size()-1];
        while(newstr3.size()<3){
            newstr3+=last;
        }
    }
    
    return newstr3;
}