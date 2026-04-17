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
#define pf(x) push_front(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
deque<ll> arr;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,cnt=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)arr.pb(i);
    while(m--){
        ll t;
        cin>>t;
        ll s=find(all(arr),t)-arr.begin();
        ll e=arr.end()-find(all(arr),t);
        cnt+=min(s,e);
        if(s<e){
            for(i=0;i<s;i++){
                arr.pb(arr.front());
                arr.pop_front();
            }
            arr.pop_front();
        }
        else{
            for(i=0;i<e;i++){
                arr.pf(arr.back());
                arr.pop_back();
            }
            arr.pop_front();
        }
    }
    cout<<cnt;
    return 0;
}
