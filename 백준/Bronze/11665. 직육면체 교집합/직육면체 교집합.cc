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

typedef tuple<ll,ll,ll> tlll;

pair<tlll,tlll> aabb(pair<tlll,tlll>a,pair<tlll,tlll>b){
	if(a.first==make_tuple(0,0,0)){
		return {{0,0,0},{0,0,0}};
	}
	auto [axm,aym,azm]=a.first;
	auto [axM,ayM,azM]=a.second;
	auto [bxm,bym,bzm]=b.first;
	auto [bxM,byM,bzM]=b.second;
	ll mx=max(axm,bxm);
	ll my=max(aym,bym);
	ll mz=max(azm,bzm);
	ll Mx=min(axM,bxM);
	ll My=min(ayM,byM);
	ll Mz=min(azM,bzM);
	if(mx>=Mx||my>=My||mz>=Mz){
		return {{0,0,0},{0,0,0}};
	}
	else return {{mx,my,mz},{Mx,My,Mz}};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	ll n;
	cin>>n;
	vector<pair<tlll,tlll>>arr(n);
	for(i=0;i<n;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		arr[i].first={x,y,z};
		cin>>x>>y>>z;
		arr[i].second={x,y,z};
	}
	pair<tlll,tlll>now=arr[0];
	for(i=1;i<n;i++){
		now=aabb(now,arr[i]);
	}
	auto [mx,my,mz]=now.first;
	auto [Mx,My,Mz]=now.second;
	cout<<(Mx-mx)*(My-my)*(Mz-mz);
	return 0;
}
