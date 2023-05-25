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

ll n, m,k;
vector<ll>arr;
ll anss;
ll ans(ll da,ll now, ll mmm){
	anss=max(anss,now);
	now-=mmm;
	if(da==n-1)return now;
	else{
		ans(da+1,now,0);
		ll p=now*k;
		if(now+p<arr[da])return 1;
		now+=p;
		for(ll i=da+1;i<n;i++){
			ans(i,(arr[i]-arr[da])*(now/arr[da])+now,p);
		}

	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	cin>>n>>m>>k;
	arr.resize(n);
	for(i=0;i<n;i++)cin>>arr[i];
	ll now=m;

	ll ma=*max_element(all(arr));
//	for(i=0;i<n-1;i++){
//		if(arr[i]>*max_element(arr.begin()+i+1,arr.end())){
//			ll p=now*k;
//			now+=p;
//			now+=(*max_element(arr.begin()+i+1,arr.end())-arr[i])*(now/arr[i]);
//			ans=max(ans,now);
//			break;
//		}
//		else if(arr[i]==*max_element(arr.begin()+i+1,arr.end())){
//			ll y=max_element(arr.begin()+i+1,arr.end())-arr.begin();
//			if(y!=n-1&&arr[y]==*max_element(arr.begin()+y+1,arr.end()))continue;
//			else{
//				ll p=now*k;
//				now+=p;
//				ans=max(ans,now);
//				now-=p;
//			}
//		}
//		if(arr[i]<arr[i+1]){
//			ll p=now*k;
//			if(now+p<arr[i])continue;
//			now+=p;
//			now+=(arr[i+1]-arr[i])*(now/arr[i]);
//			ans=max(now,ans);
//			now-=p;
//		}
//	}
	anss=m;
	ans(0,m,0);
	cout<<anss;


	return 0;
}
