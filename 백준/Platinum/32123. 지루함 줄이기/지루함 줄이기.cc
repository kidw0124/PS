#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void preprocess() {
    ;
}

void solve() {
    ll i,j;
    ll n,m;
    map<ll,ll>po,re;
    map<ll,ll>dppo,dpre;
    cin>>n>>m;
    string str;
    cin>>str;
    ll now=0,mini=0,maxi=0;
    for(i=0;i<n*2;i++){
        now+=(str[i]=='1'?1:-1);
        po[now]++;
        mini=min(mini,now),maxi=max(maxi,now);
    }
    re=po;
    dppo[mini]=0;
    while(po.size()>1 && po.begin()->first<0){
        auto [a,b]=*next(po.begin());
        auto [pa,pb]=*po.begin();
        po.erase(pa);
        dppo[a]=dppo[pa]+pb;
        po[pa+2]+=pb;
    }
    dpre[maxi]=0;
    po=re;
    while(po.size()>1 && po.rbegin()->first>0){
        auto [a,b]=*next(po.rbegin());
        auto [pa,pb]=*po.rbegin();
        po.erase(pa);
        dpre[a]=dpre[pa]+pb;
        po[pa-2]+=pb;
    }
//    for(auto [a,b]:dppo){
//        cout<<a<<" "<<b<<"\n";
//    }
//    cout<<"======\n";
//    for(auto [a,b]:dpre){
//        cout<<a<<" "<<b<<"\n";
//    }
    ll ans=LLONG_MAX;
    for(auto [a,b]:dpre){
        auto it=dppo.lower_bound(a-m);
        if(it!=dppo.end())ans=min(ans,b+it->second);
    }
    cout<<ans<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
}