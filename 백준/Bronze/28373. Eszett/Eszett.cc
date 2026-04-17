#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int i,j,k;
    int n=str.size();
    set<string>ans;
    for(auto &k:str)k=k-'A'+'a';
    for(i=0;i<(1<<n);i++){
        bitset<20>bs(i);
        string ss;
        bool b=0;
        for(j=0;j<n-1;j++){
            if(bs[j]){
                if(j){
                    if(bs[j-1]){
                        b=1;
                        break;
                    }
                    else if(str[j]=='s'&&str[j+1]=='s'){
                        ss+="B";
                        j++;
                    }
                    else {
                        b=1;
                        break;

                    }
                }
                else{
                    if(str[j]=='s'&&str[j+1]=='s') {
                        ss += "B";
                        j++;
                    }
                    else {
                        b=1;
                        break;
                    }
                }
            }
            else ss+=str[j];
        }
        if(j==n-1)ss+=str[j];
        if(!b){
            ans.insert(ss);
        }
    }
    for(auto k:ans){
        cout<<k<<'\n';
    }
}