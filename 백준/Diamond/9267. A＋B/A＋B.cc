#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef __int128 ll;
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

tuple<ll,ll,ll>ext_gcd(ll a, ll b){
	if(!b)return{a,1,0};
	else{
		ll g,x,y;
		tie(g,x,y)=ext_gcd(b,a%b);
		return {g,y,x-a/b*y};
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	LL a,b,c;
	cin>>a>>b>>c;
	if(!a&&!b){
		cout<<(c?"NO\n":"YES\n");
		return 0;
	}
	else if(!a){
		cout<<(c%b?"NO\n":"YES\n");
		return 0;
	}
	else if(!b){
		cout<<(c%a?"NO\n":"YES\n");
		return 0;
	}
	ll g,x,y;
	tie(g,x,y)=ext_gcd(a,b);
	if(c%g){
		cout<<"NO\n";
		return 0;
	}
	x*=c/g;
	y*=c/g;
	for(i=floor(-g*x/(double)b)+1;i<=floor(g*y/(double)a);i++){
		if(x+i*b/g>=0&&y-i*a/g>=0&&gcd(x+i*b/g,y-i*a/g)==1){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";

	return 0;
}
