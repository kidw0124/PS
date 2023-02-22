#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

void solve(){
    ll i;
    ll n,b,r;
    cin>>n>>b>>r;
    vector<ll>v(n);
    for(i=0;i<n;i++){
		cin>>v[i];
		//cout<<v[i]<<'\n';
    }
    vector<ll>rarr(b+1,-1),sum(n*b+1);
    ll now=0,q=1,j=0;
    while(b-now>=v[0]&&rarr[now]==-1){
		rarr[now]=j;
		for(i=0;i<n;i++){
			//cout<<now<<' '<<v[i]<<'\n';
			if(now+v[i]>b){
				q++;
				now=0;
			}
			now+=v[i];
		}
		sum[++j]=q;
    }
    ll per=j;
    if(rarr[now]!=-1){
		per=j-rarr[now];
		ll ans=sum[rarr[now]];
		r-=rarr[now];
		ans+=r/per*(sum[j]-sum[rarr[now]])+sum[r%per+rarr[now]]-sum[rarr[now]];
		cout<<ans<<'\n';
    }
    else cout<<r/per*sum[per]+sum[r%per]<<'\n';


}

int main() {
    setup();
    ll t;
    cin>>t;
    while(t--){
		solve();
    }


}
