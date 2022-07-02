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
struct dat{
	time_t tt;
	ll lev;
	long double p;
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	ll n;
	cin>>n;
	if(n==0){
		cout<<0;
		return 0;
	}
	vector<dat>arr(n);
	for(i=0;i<n;i++){
		char t;
		struct tm tim={0};
		cin>>tim.tm_year>>t>>tim.tm_mon>>t>>tim.tm_mday>>tim.tm_hour>>t>>tim.tm_min>>t>>tim.tm_sec>>arr[i].lev;
		tim.tm_year-=1900,tim.tm_mon--;
		arr[i].tt=mktime(&tim);
		//cout<<arr[i].tt<<'\n';
	}
	for(i=0;i<n;i++){
		arr[i].p=max(pow((long double)0.9,n-i-1),pow((long double)0.5,-difftime(arr[i].tt,arr[n-1].tt)/(long double)(365*24*3600)));
		//cout<<fixed<<setprecision(10)<<pow((long double)0.9,n-i-1)<<' '<<difftime(arr[i].tt,arr[n-1].tt)/(long double)(365*24*3600)<<' '<<pow((long double)0.5,-difftime(arr[i].tt,arr[n-1].tt)/(long double)365)<<'\n';
	}
	long double u=0,d=0;
	for(i=0;i<n;i++){
		u+=arr[i].p*arr[i].lev;
		d+=arr[i].p;
		//cout<<arr[i].p<<' '<<arr[i].lev<<'\n';
	}
	cout<<round(u/d);

	return 0;
}
