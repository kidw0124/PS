#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<int>arr(n+1);
    auto cmp=[&arr](tuple<int,int,int>a,tuple<int,int,int>b){
        if(arr[get<0>(a)]>=2)return false;
        if(arr[get<0>(b)]>=2)return true;
        else return get<2>(a)>get<2>(b);
    };
//    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,decltype(cmp)>pq;
    vector<tuple<int,int,int>>pq;
    for(i=0;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        pq.push_back({a,b,c});
    }
    for(i=0;i<3;i++){
        sort(all(pq),cmp);
        ll a,b,c;
        tie(a,b,c)=pq[0];
        cout<<a<<' '<<b<<'\n';
        arr[a]++;
        pq[0]={a,b,-1};
    }

    return 0;
}
