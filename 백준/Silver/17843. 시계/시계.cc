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
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (!ndebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
	ll t;
	cin>>t;
	while(t--){
		long double h,m,s;
		cin>>h>>m>>s;
		h=h*360/12.0+m*(360/12.0/60.0)+s*(360/12.0/60.0/60.0);
		m=m*(360/60.0)+s*(360/60.0/60.0);
		s=s*(360/60.0);
		cout<<fixed<<setprecision(6)
			<<min({abs(h-m),abs(360-(h-m)),abs(360+(h-m)),abs(m-s),abs(360-(m-s)),abs(360+(m-s)),abs(h-s),abs(360-(h-s)),abs(360+(h-s))})<<'\n';
	}
    return 0;
}
