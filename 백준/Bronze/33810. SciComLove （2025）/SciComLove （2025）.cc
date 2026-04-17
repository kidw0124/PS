#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    auto ans=0;
    for(auto i=0;i<str.size();i++){
        if(str[i]!="SciComLove"[i])ans++;
    }
    cout<<ans;
}