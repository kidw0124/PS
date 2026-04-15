#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void setup(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

void solve(ll tc){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<string>arr(n);
    map<string,vector<string>>mp;
    auto str1tostr2=[](string&s){
        string ret;
        for(const auto&k:s){
            if(k<='c')ret+='2';
            else if(k<='f')ret+='3';
            else if(k<='i')ret+='4';
            else if(k<='l')ret+='5';
            else if(k<='o')ret+='6';
            else if(k<='s')ret+='7';
            else if(k<='v')ret+='8';
            else if(k<='z')ret+='9';
        }
        return ret;
    };
    for(i=0;i<n;i++){
        string str;
        cin>>str;
        mp[str1tostr2(str)].push_back(str);
    }
    for(i=0;i<m;i++){
        string str;
        cin>>str;
        cout<<mp[str].size()<<' ';
        for(auto&k:mp[str])cout<<k<<' ';
        cout<<'\n';
    }

}

void preprocess(){
    ll i,j,k;
}

int main(){
    setup();preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(t+1);
    }
    return 0;
}