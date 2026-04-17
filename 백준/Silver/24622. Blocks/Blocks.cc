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
	ll n;
	cin>>n;
	vector<string>arr(4);
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	for(i=0;i<n;i++){
		string s;
		cin>>s;
		bool t=0;
		vector<int>permu(4);
		iota(all(permu),0);
		do{
			for(j=0;j<s.size();j++){
				if(find(all(arr[permu[j]]),s[j])==arr[permu[j]].end())break;
			}
			if(j==s.size())t=1;
		}while(next_permutation(all(permu)));
		cout<<(t?"YES":"NO")<<'\n';
	}
	return 0;
}
