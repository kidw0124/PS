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
vector<pll> arr;
ll n,m;
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ll t;
            cin>>t;
            if(t)arr.push_back({i,j});
        }
    }
    sort(arr.begin(),arr.end());
    ll cnt=1;
    deque<ll>pq(2,999);
    pq[0]=(arr[0].second);
    for(i=1;i<arr.size();i++){
//        for(auto k:pq){
//            cout<<k<<' ';
//        }
//        cout<<'\n';
        if(arr[i].second<pq[0]){
            cnt++;
            pq.push_front(arr[i].second);
        }
        else{
            j=-1;
            while(arr[i].second>=pq[++j]);
            if(j-1==pq.size())pq.push_back(arr[i].second);
            else pq[j-1]=arr[i].second;
        }
    }
    cout<<cnt;
    return 0;
}
