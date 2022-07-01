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
	ll t;
	cin>>t;
	ll p1=97,p2=1031;
	vector<vector<ll>>comb1(p1+1,vector<ll>(p1+1));
	for(i=0;i<p1;i++){
		comb1[i][0]=comb1[i][i]=1;
		for(j=1;j<i;j++){
			comb1[i][j]=comb1[i-1][j-1]+comb1[i-1][j];
			comb1[i][j]%=p1;
		}
	}
	vector<vector<ll>>comb2(p2+1,vector<ll>(p2+1));
	for(i=0;i<p2;i++){
		comb2[i][0]=comb2[i][i]=1;
		for(j=1;j<i;j++){
			comb2[i][j]=comb2[i-1][j-1]+comb2[i-1][j];
			comb2[i][j]%=p2;
		}
	}
	while(t--){
		ll m1,m2,n1,n2;
		cin>>n1>>m1;
		if(n1==0&&m1==1){
			cout<<"1\n";
			continue;
		}
		if(n1-m1+1<0||m1<2){
			cout<<"0\n";
			continue;
		}
		else if(m1==2){
			cout<<"1\n";
			continue;
		}
		n1-=1,m1-=2;
		m2=m1,n2=n1;
		ll ans=1,ans1=1,ans2=1;
		while(m1){
			ans1*=comb1[n1%p1][m1%p1];
			ans1%=p1;
			n1/=p1,m1/=p1;
		}
		while(m2){
			ans2*=comb2[n2%p2][m2%p2];
			ans2%=p2;
			n2/=p2,m2/=p2;
		}
		ll inv1=659,inv2=35;
		ans=ans2*inv1*p1+ans1*inv2*p2;
		cout<<ans%100007<<'\n';
	}
	return 0;
}
