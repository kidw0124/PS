#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
vector<pll> arr;

unordered_map<ll,pll>par;

string print(ll n){
    ll now=n;
    string ans;
    while(now>1) {
        auto [p, add] = par[now];
        for (ll i = 0; i < add; i++)ans.push_back('.');
        ans.push_back('#');
        now = p;
    }
    return ans.substr(0,ans.size()-1);
}
ll mmm=100;
ll n;

constexpr int mod = 1e9 + 7;

ll ipow(ll x, ll n) {
    ll ret = 1;
    for (;n ; n >>= 1) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
    }
    return ret;
}

ll modinv(ll k){
    return ipow(k, mod - 2);
}

priority_queue<tuple<ll,ll,ll>>pq;

ll cnt=0;

void ans(ll wid,ll nn,ll now){
    if(cnt>3e6)return;
    pq.pop();
    if(nn==n){
        string str=print(nn);
        cout<<str<<'\n'<<str;
        exit(0);
    }
    for(ll i=now;i<mmm;i++){
        auto [idx,p]=arr[i];
        if(wid+idx+1<=80){
            par[p*nn%mod]={nn,idx};
            ans(wid+idx+1,nn*p%mod,i);
            cnt++;
        }
    }
    return;
}

void solve() {
    arr.push_back({2,2});
    arr.push_back({3,3});
    for(ll i=4;i<mmm;i++){
        arr.push_back({i,(arr[i-3].second+arr[i-4].second)%(ll)(1e9+7)});
    }
    mmm=arr.size();
    sort(arr.begin(), arr.end(),[](const pll&a,const pll&b){
        return a.second==b.second?a.first<b.first:a.second>b.second;
    });
//    vector<pll>brr;
//    for(ll i=0;i<mmm;i++){
//        ll j;
//        for(j=2;j*j<=arr[i].second;j++){
//            if(arr[i].second%j==0)break;
//        }
//        if(j*j>=arr[i].second){
//            brr.push_back(arr[i]);
//        }
//    }
//    arr=brr;
//    mmm=arr.size();
    cin>>n;
    if(n==1){
        cout<<".\n.";
        return;
    }
    else if(n==0){
        cout<<".##\n##.";
        return;
    }
    else {
        par[1]={0,0};
        ans(0,1,0);
        for(auto [idx,p]:par){
            if(par.find(n* modinv(idx)%mod)!=par.end()){
                string a1=print(n* modinv(idx)%mod);
                string a2=print(idx);
//                cout<<a1<<'\n'<<a2<<"\n";
                cout<<a1<<"#"<<a2<<"\n";
                cout<<a1<<"#"<<a2<<"\n";
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();
    return 0;
}