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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	vector<vector<ll>>arr(9,vector<ll>(9));
	vector<vector<ll>>brr(9,vector<ll>(9));
	ll n;
	cin>>n;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>arr[i][j];
			arr[i][j]-=n;
		}
	}
	for(int i=0;i<8;i++){
		ll x=0,y=0;
		for(int j=0;j<8;j++){
			x+=arr[i][j];
			y+=arr[j][i];
		}
		arr[i][8]=x;
		arr[8][i]=y;
	}
	vector<vector<bool>>chk(8,vector<bool>(8));
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			chk[i][j]=(arr[i][8]+arr[8][j]+arr[i][j])%2;
			if(chk[i][j]){
				for(ll k=0;k<8;k++){
					brr[i][k]++;
					brr[8][k]++;
					brr[k][j]++;
					brr[k][8]++;
				}
				brr[i][j]--;
				brr[i][8]--;
				brr[8][j]--;
			}
		}
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(chk[i][j]){
				if((arr[i][8]+arr[8][j]-arr[i][j]+10000)%4==(brr[i][8]+brr[8][j]-brr[i][j]+10000)%4){
					cout<<"+ ";
				}
				else cout<<"- ";
			}
			else{
				cout<<". ";
			}
		}
		cout<<'\n';
	}
	return 0;
}
