#include<bits/stdc++.h>
#include  <math.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#define M_PI		3.14159265358979323846
using namespace std;
typedef long long ll;
typedef long double ld;
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

struct dt{
	ld x,y,d,s;
	ld sind,cosd;
	void input(){
		cin>>x>>y>>d>>s;
		sind=sin(d*M_PI/180);
		cosd=cos(d*M_PI/180);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		ld r;
		cin>>n>>r;
		vector<dt>arr(n);
		for(i=0;i<n;i++){
			arr[i].input();
		}
		ll ans=(ll)1e18;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				ld x=arr[i].x-arr[j].x;
				ld y=arr[i].y-arr[j].y;
				ld vx=arr[i].s*arr[i].sind-arr[j].s*arr[j].sind;
				ld vy=arr[i].s*arr[i].cosd-arr[j].s*arr[j].cosd;
				ld D=(x*vx+y*vy)*(x*vx+y*vy)-(vx*vx+vy*vy)*(x*x+y*y-r*r);
				if(vx*vy+vy*vy==0){
					if(x*x+y*y<=r*r)ans=0;
				}
				else{
					if(D<0)continue;
					ld a=(-x*vx-y*vy-sqrt(D))/(vx*vx+vy*vy);
					ld b=(-x*vx-y*vy+sqrt(D))/(vx*vx+vy*vy);
					if(b>=0&&a<0)ans=0;
					else if(a>0)ans=min(ans,(ll)round(a));
				}
			}
		}
		if(ans!=(ll)1e18)cout<<ans<<'\n';
		else cout<<"No collision.\n";
	}

	return 0;
}
