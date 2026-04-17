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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	vector<pll>arr;
	ll n;
	cin>>n;
	arr.resize(n);
	for(i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr.begin(),arr.end(),[](pll a,pll b){
			return a.first==b.first?a.second>b.second:a.first<b.first;
		});
	ll ans=arr[0].second-arr[0].first,now=arr[0].second;
	for(i=1;i<n;i++){
		if(arr[i].first>now){
			ans+=arr[i].second-arr[i].first;
			now=arr[i].second;
		}
		else if(arr[i].second>now){
			ans+=arr[i].second-now;
			now=arr[i].second;
		}
	}
	cout<<ans;
	return 0;
}
