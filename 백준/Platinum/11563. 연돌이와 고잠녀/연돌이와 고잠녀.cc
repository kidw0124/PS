#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef double ld;

using ll = long long;
using pld=pair<ld,ld>;
using segment = pair<pld,pld>;

pld operator+(const pld&a, const pld&b){
    return {a.first+b.first,a.second+b.second};
}

pld operator*(const ll&a, const pld&b){
    return {a*b.first,a*b.second};
}
pld operator/(const pld&b,const ll&a){
    return {b.first/a,b.second/a};
}

ld dist(const pld&a, const pld&b){
    return sqrt((a.first-b.first)*(a.first-b.first)
                +(a.second-b.second)*(a.second-b.second));
}

ld dist(const pld&a, const segment &b){
    ld af=dist(a,b.first),as=dist(a,b.second),di=dist(b.first,b.second);
    ld s=(af+as+di)/2;
    if(af<as)swap(af,as);
    if(as*as+di*di>af*af){
        ld S=sqrt(s*(s-af)*(s-as)*(s-di));
        return S/di*2;
    }
    else return as;
}

ld dist(const segment &b,const pld&a){
    return dist(a,b);
}

void solve()
{
    ll k, n, m, i, j, l;
    cin>>n>>m;
    vector<segment>arr(n);
    vector<segment>brr(m);
    for(i=0;i<n;i++){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
    }
    for(i=0;i<m;i++){
        cin>>brr[i].first.first>>brr[i].first.second>>brr[i].second.first>>brr[i].second.second;
    }
    ld ans=INT_MAX;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ans=min({ans,dist(arr[i],brr[j].first),dist(arr[i],brr[j].second),dist(arr[i].second,brr[j]),dist(arr[i].first,brr[j])});
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
//    cin >> t;
    while(t--)solve();

    return 0;
}