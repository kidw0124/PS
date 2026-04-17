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

ll n,w,t,k;

vector<ll>arr;

int ans(ll now,vector<ll>nowarr,ll step){

	ll i;	vector<ll>newarr=nowarr;

	for(i=0;i<n;i++){

		if(i==now&&step>0)continue;

		ll x=0;

		if(i==0){

			x=nowarr[1]>0;

		}

		else if(i==n-1)x=nowarr[n-2]>0;

		else x=(nowarr[i-1]>0)+(nowarr[i+1]>0);

		newarr[i]=nowarr[i]-3+x;

	}

	nowarr=newarr;

	if(step==t-1){

		return count_if(all(nowarr),[](int x){

			return x>0;

		})>=k?1:0;

	}

	else{

		ll ret=0;

		if(now>0)ret+=ans(now-1,nowarr,step+1);

		if(now<n-1)ret+=ans(now+1,nowarr,step+1);

		ret+=ans(now,nowarr,step+1);

		return ret;

	}

}

int main(){

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	ll i,j;

	cin>>n>>w>>t>>k;

	arr.resize(n);

	for(i=0;i<n;i++){

		cin>>arr[i];

	}

	cout<<ans(w,arr,0);

	return 0;

}