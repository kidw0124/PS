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

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	ll n,m;
	cin>>n>>m;
	deque<pair<long double,long double>>arr,brr;
	long double tot=0;
	for(i=0;i<n;i++){
		pair<long double,long double>x;
		cin>>x.first>>x.second;
		if(x.first<m)arr.push_back(x);
		else if(x.first>m) brr.push_back(x);
		else tot+=x.second;
	}
	sort(all(arr));
	sort(all(brr));
	reverse(all(arr));
	while(!arr.empty()&&!brr.empty()){
		auto& [a,x]=arr[0];
		auto& [b,y]=brr[0];
		if((m-a)*x<y*(b-m)){
			tot+=x+(m-a)*x/(b-m);
			y-=(m-a)*x/(b-m);
			arr.pop_front();
		}
		else if((m-a)*x>y*(b-m)){
			tot+=y+(b-m)*y/(m-a);
			x-=(b-m)*y/(m-a);
			brr.pop_front();
		}
		else{
			tot+=x+y;
			arr.pop_front();
			brr.pop_front();
		}
	}
	cout<<fixed<<setprecision(10)<<tot;
	return 0;
}
