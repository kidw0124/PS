#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n;
ll arr[3000][3000];

tuple<ll,ll,ll> operator+(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){
    return {get<0>(a)+get<0>(b),get<1>(a)+get<1>(b),get<2>(a)+get<2>(b)};
}

tuple<ll,ll,ll> func(int a, int b, int s){
    ll p=arr[a][b],l=0;
    if(s==1){
        if(p==1)return {0,1,0};
        else if(p==-1)return {0,0,1};
        else return {1,0,0};
    }
    for(int i=a;i<s+a;i++){
        for(int j=b;j<b+s;j++){
            if(p!=arr[i][j])l=1;
        }
    }
    if(!l){
        if(p==1)return {0,1,0};
        else if(p==-1)return {0,0,1};
        else return {1,0,0};
    }
    else{
        return func(a,b,s/3)+func(a+s/3,b,s/3)+func(a+2*(s/3),b,s/3)
                +func(a,b+s/3,s/3)+func(a+s/3,b+s/3,s/3)+func(a+2*(s/3),b+s/3,s/3)
                +func(a,b+2*(s/3),s/3)+func(a+s/3,b+2*(s/3),s/3)+func(a+2*(s/3),b+2*(s/3),s/3);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    tuple<ll,ll,ll> ans=func(0,0,n);
    cout<<get<2>(ans)<<'\n'<<get<0>(ans)<<'\n'<<get<1>(ans);
    return 0;
}
