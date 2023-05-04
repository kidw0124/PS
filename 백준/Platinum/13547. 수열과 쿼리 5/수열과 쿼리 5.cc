#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

ll sn;

struct query{
    ll s,e;
    ll ord, ans;
};

bool cmp1(const query&l,const query&r){
    return l.s/sn==r.s/sn?l.e<r.e:l.s<r.s;
}
bool cmp2(const query&l,const query&r){
    return l.ord<r.ord;
}

void solve(){
    ll i,j,k;
    ll n,q,s,e;
    cin>>n;
    vector<ll>cnt(1'000'000+1),arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>q;
    sn= sqrt(n);
    vector<query>que(q);
    ll ans=0;
    for(i=0;i<q;i++){
        cin>>que[i].s>>que[i].e;
        que[i].s--,que[i].e--;
        que[i].ord=i;
    }
    sort(all(que),cmp1);
    s=que[0].s,e=que[0].e;
    for(i=s;i<=e;i++){
        if(cnt[arr[i]]++==0)ans++;
    }
    que[0].ans=ans;
    for(i=1;i<q;i++){
        while(s<que[i].s){
            if(cnt[arr[s++]]--==1)ans--;
        }
        while(s>que[i].s){
            if(cnt[arr[--s]]++==0)ans++;
        }
        while(e<que[i].e){
            if(cnt[arr[++e]]++==0)ans++;
        }
        while(e>que[i].e){
            if(cnt[arr[e--]]--==1)ans--;
        }
        que[i].ans=ans;
    }
    sort(all(que),cmp2);
    for(i=0;i<q;i++)cout<<que[i].ans<<'\n';
}

int main() {
    setup();
    ll t=1;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve();
    }
    return 0;
}
