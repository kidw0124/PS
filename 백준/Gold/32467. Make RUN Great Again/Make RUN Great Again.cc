#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;

void solve() {
    ll i,j;
    ll n,k,x;
    cin>>n>>k>>x;
    vector<pll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    ll st=0,en=1e12;
    while(st<en){
        ll mid=(st+en)>>1;
        priority_queue<ll>pq;
        for(i=0;i<n;i++){
            if(mid>=arr[i].first){
                pq.push(0);
            }
            else{
                ll d=arr[i].first-mid;
                pq.push(d*arr[i].second);
            }
        }
        for(i=0;i<x-1;i++){
            pq.pop();
        }
        ll ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        if(ans<k)en=mid;
        else st=mid+1;
    }
    cout<<st;
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    //cin >> tc;
    while (tc--) solve();
}