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
	vector<vector<ll>>arr(str.size()+1,vector<ll>(26));
	for(i=0;i<str.size();i++){
		arr[i+1]=arr[i];
		arr[i+1][str[i]-'a']++;
	}
	ll n;
	cin>>n;
	while(n--){
		char x;
		cin>>x>>i>>j;
		cout<<arr[j+1][x-'a']-arr[i][x-'a']<<'\n';
	}
	return 0;
}
