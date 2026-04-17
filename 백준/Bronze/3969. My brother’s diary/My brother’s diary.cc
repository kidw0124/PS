#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void solve() {
    ll i,j,k;
    string str;
    getline(cin,str);
    vector<ll>arr(26);
    for(i=0;i<str.size();i++){
        if(isalpha(str[i]))arr[str[i]-'A']++;
    }
    ll m=*max_element(arr.begin(),arr.end());
    if(count(arr.begin(),arr.end(),m)>1){
        cout<<"NOT POSSIBLE\n";
        return;
    }
    else{
        ll idx=max_element(arr.begin(),arr.end())-arr.begin();
        ll offset=0;
        if(idx<5){
            offset=26+idx-4;
        }
        else offset=idx-4;
        cout<<offset%26<<' ';
        for(auto k:str){
            if(isalpha(k)){
                ll p=k-'A';
                p+=26-offset;
                p%=26;
                cout<<(char)(p+'A');
            }
            else cout<<k;
        }
        cout<<'\n';
    }
}

int main(){
    setup();
    ll t;
    cin >> t;
    string str;
    getline(cin,str);
    for(ll tc = 0; tc < t; tc++) {
        solve();
    }
}