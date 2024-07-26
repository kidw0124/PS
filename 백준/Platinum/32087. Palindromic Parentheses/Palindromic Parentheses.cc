#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll i,j;
    ll n, m;
    cin>>n>>m;
    if(m<n/2||m==n)cout<<-1;
    else{
        ll dif=m-n/2;
        string str;
        for(i=0;i<n/2-dif;i++){
            str+='(';
        }
        for(i=0;i<n/2-dif;i++){
            str+=')';
        }
        string tmp1,tmp2;
        for(i=0;i<dif/2;i++)tmp1+="()";
        for(i=0;i<dif-dif/2;i++)tmp2+="()";
        cout<<tmp1+str+tmp2;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    solve();
    return 0;
}