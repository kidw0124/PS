#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

#ifdef ONLINEJUDGE
constexpr bool isdebug=false;
#else
constexpr bool isdebug=true;
#endif

#define debug if(isdebug)cout<<"[DEBUG] "
#define debugc(x) if(isdebug){cout<<"[DEBUG] "<<#x<<" : ";for(int j=0;j<x.size();j++)cout<<x[j]<<' ';cout<<"\n";}
#define debugv(x) if(isdebug){cout<<"[DEBUG] "<<#x<<" : ";cout<<x<<' ';cout<<"\n";}

void solve(){
    ll i,j,k;
    string str1,str2;
    cin>>str1>>str2;
    if((count(str1.begin(), str1.end(),'B')&1)!=(count(str2.begin(), str2.end(),'B')&1)){
        cout<<"NO\n";
        return;
    }
    string s1="Y",s2="Y";
    for(auto k:str1){
        if(s1.back()==k)s1.pop_back();
        else if(k!='B')s1.push_back(k);
    }
    for(auto k:str2){
        if(s2.back()==k)s2.pop_back();
        else if(k!='B')s2.push_back(k);
    }
    if(s1!=s2){
        cout<<"NO\n";
    }
    else cout<<"YES\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}