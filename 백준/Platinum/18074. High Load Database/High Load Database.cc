#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void solve() {
    ll i,j;
    ll n,q;
    cin>>n;
    vector<ll>arr(n);
    for(auto &x:arr)cin>>x;
    cin>>q;
    vector<pair<pll,ll>>brr(q);
    for(i=0;i<q;i++){
        cin>>brr[i].first.first;
        brr[i].first.second=i;
    }
    sort(brr.begin(), brr.end(),greater<>());
    ll MAXM = 1e6+5,mini=*max_element(arr.begin(), arr.end());
    auto get_cnt=[&](ll x){
        if(brr[x].first.first<mini){
            return brr[x].second=1e9;
        }
        if(brr[x].second)return brr[x].second;
        ll cnt=0,now=0;
        for(j=0;j<n;){
            while(j<n&&now+arr[j]<=brr[x].first.first){
                now+=arr[j],j++;
            }
            cnt++;
            now=0;
        }
        return brr[x].second=cnt;
    };
    for(i=0;i<q;i++){
        ll gi=get_cnt(i);
        ll st=i,en=q-1;
        while(st<en){
            ll mid=(st+en+1)>>1;
            ll gm=get_cnt(mid);
            if(gm>gi)en=mid-1;
            else st=mid;
        }
        for(j=i+1;j<st;j++)brr[j].second=brr[j-1].second;
        i=st;
    }
    for(auto &[p,x]:brr){
        swap(p.first,p.second);
    }
    sort(brr.begin(), brr.end());
    for(i=0;i<q;i++){
        if(brr[i].second==1e9)cout<<"Impossible\n";
        else cout<<brr[i].second<<'\n';
    }
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}