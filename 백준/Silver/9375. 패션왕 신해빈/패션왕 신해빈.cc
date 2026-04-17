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
ll t,n;
map<string, ll>arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        arr.clear();
        cin>>n;
        for(i=0;i<n;i++){
            string s,ss;
            cin>>s>>ss;
            if(arr.find(ss)!=arr.end()){
                arr[ss]++;
            }
            else{
                arr[ss]=1;
            }
        }
        ll ans=1;
        for(auto k:arr){
            ans*=k.second+1;
        }
        cout<<ans-1<<'\n';
    }

    return 0;
}
