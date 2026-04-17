#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a+b;}

struct rational{
    ll q,p;
    void normalize(){
        ll g=gcd(p,q);
        p/=g,q/=g;
    }
    bool operator<(const rational&r){
        return p*r.q<q*r.p;
    }
};

void solve(){
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>primes;
    vector<bool>isprime(n+1);
    for(i=2;i<=n;i++){
        if(!isprime[i]){
            if(n%i==0)primes.push_back(i);
            for(j=i*i;j<=n;j+=i){
                isprime[j]=1;
            }
        }
    }
    auto getratio = [&](vector<ll> arr, ll p){
        ll i,j;
        rational ans;
        multiset<ll>ms;
        vector<ll>group(p);
        for(i=0;i<n;i++){
            group[i%p]+=arr[i];
        }
        for(auto k:group)ms.insert(k);
        ans={*ms.begin(),*ms.rbegin()};
        ans.normalize();
        for(i=0;i<n-1;i++){
            ms.erase(ms.find(group[i%p]));
            ms.erase(ms.find(group[(i+1)%p]));
            group[i%p]+=arr[i+1]-arr[i];
            group[(i+1)%p]+=arr[i]-arr[i+1];
            swap(arr[i],arr[i+1]);
            ms.insert(group[i%p]);
            ms.insert(group[(i+1)%p]);
            rational tmp={*ms.begin(),*ms.rbegin()};
            tmp.normalize();
            if(tmp<ans)ans=tmp;
        }
        return ans;
    };
    rational ans={1,1'000'000'000};
    for(auto p:primes){
        auto tmp=getratio(arr,p);
        if(tmp<ans)ans=tmp;
    }
    cout<<ans.p<<' '<<ans.q<<'\n';

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)solve();
}