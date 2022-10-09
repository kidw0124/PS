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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag ,tree_order_statistics_node_update >;
using ordered_multi_set = tree<int, null_type, less_equal <int>, rb_tree_tag ,tree_order_statistics_node_update >;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	ll n;
	cin>>n;
	vector<ll>arr(n);
	map<int, set<int>>mp;
	for(i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]].insert(i);
	}
	ll t;
	cin>>t;
	while(t--){
		ll x=0;
		cin>>x;
		if(x==1){
			ll a,b;
			cin>>a>>b;
			a--;
			mp[arr[a]].erase(a);
			if(mp[arr[a]].empty())mp.erase(arr[a]);
			arr[a]=b;
			mp[arr[a]].insert(a);
		}
		else{
			cout<<*(mp.begin()->second.begin())+1<<'\n';
		}
	}
	return 0;
}
