#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod=1e9+7;

void solve(){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    struct tm t = {0};
    t.tm_year = n-1900;
    t.tm_mon = m-1;
    t.tm_mday = m;
    time_t time = mktime(&t);
    time -= 86400*m;
    t = *localtime(&time);
    cout<<t.tm_year+1900<<" "<<t.tm_mon+1<<" "<<t.tm_mday<<"\n";
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    ll t;
    cin>>t;
    while(t--)solve();
}