#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
#ifdef kidw0124
    constexpr bool xdebug = true;
#else
    constexpr bool xdebug = false;
#endif
#define debug if constexpr (xdebug) cout<<"[DEBUG] "
void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif
}

struct team{
    ll n;
    vector<pll>pans;
    ll p()const{
        ll ans=0;
        for(auto [a,b]:pans){
            ans+=a*b;
        }
        return ans;
    }
    ll c() const {
        return count_if(pans.begin(), pans.end(),[](auto&x){return x.first==1;});
    }
    bool operator<(const team&r){
        return c()==r.c()?p()==r.p()?n>r.n:p()<r.p():c()>r.c();
    }
    bool operator==(const team&r){
        return c()==r.c()&&p()==r.p();
    }
};

void preprocess(){
    ll i,j,k;


}

void solve(ll testcase){
    ll i,j,k;
    ll m,t,p,r;
    while(cin>>m>>t>>p>>r,m){
        vector<team> arr(t);
        for(auto &k:arr)k.pans.resize(p+1);
        for(i=0;i<t;i++){
            arr[i].n=i+1;
        }
        for(i=0;i<r;i++){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            if(d==0){
                arr[b-1].pans[c].second+=a;
                arr[b-1].pans[c].first=1;
            }
            else{
                arr[b-1].pans[c].second+=20;
            }
        }
        sort(arr.begin(),arr.end());
        for(i=0;i<t;i++){
            if(i){
                if(arr[i]==arr[i-1]){
                    cout<<"=";
                }
                else cout<<",";
            }
            cout<<arr[i].n;
        }
        cout<<'\n';
    }
}


int main(){
    setup();
    preprocess();
    ll te=1;
//    cin>>te;
    for(ll tc=1;tc<=te;tc++){
        solve(tc);
    }
}