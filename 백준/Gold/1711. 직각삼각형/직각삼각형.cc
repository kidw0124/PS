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
	int i,j,k;
	ll n;
	cin>>n;
	vector<pll>arr(n);
	for(i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	vector<vector<ll>>edges(n,vector<ll>(n));
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			edges[i][j]=(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)
							+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
		}
	}
	int cnt=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				ll a=edges[i][j],b=edges[j][k],c=edges[i][k];
				if(a+b+c==(max({a,b,c})<<1))cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
