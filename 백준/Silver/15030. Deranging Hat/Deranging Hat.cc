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
	string str;
	cin>>str;
	string org=str;
	sort(all(org));
	ll n=str.size();
	stack<pll>stk;
	for(i=0;i<n;i++){
		if(str[i]!=org[i]){
			ll t=find(str.begin()+i+1,str.end(),org[i])-str.begin();
			stk.push({t+1,i+1});
			swap(str[t],str[i]);
		}
	}
	while(!stk.empty()){
		cout<<stk.top().first<<' '<<stk.top().second<<'\n';
		stk.pop();
	}
	return 0;
}
