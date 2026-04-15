#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using ld=long double;
#ifdef kidw0124
constexpr bool ddebug=true;
#else
constexpr bool ddebug=false;
#endif

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess(){
    ll i,j,k;

}

//int a[510][510], row[501][501], col[501][501];
void solve(ll tc){
    ll a,b;
    auto is_prime=[](ll x){
        if(x<2)return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0)return false;
        }
        return true;
    };
    cin>>a>>b;
    if(a+2==b&&is_prime(a)&&is_prime(b))cout<<"Y\n";
    else cout<<"N\n";
}

int main(){
    setup();
    ll t; t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
}