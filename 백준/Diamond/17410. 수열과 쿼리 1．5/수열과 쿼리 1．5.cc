#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <immintrin.h>
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

alignas(16) uint16_t arr[200000], C[16];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	ll n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	ll t;
	cin>>t;
	while(t--){
		ll k;
		cin>>k;
		if(k&1){
			ll a,b;
			cin>>a>>b;
			a--;
			arr[a]=b;
		}
		else{
            for(int i=0;i<16;i++)C[i]=0;
			ll l,r;
            short c;
			cin>>l>>r>>c;
			l--,r--;
			ll a=0;
			while(l&15&&l<=r)a+=arr[l++]>c;
			ll d=(r-l+1)>>4<<4;
            __m256i ans=_mm256_load_si256((__m256i*)C);
			const __m256i x=_mm256_set1_epi16((uint16_t)c);
            const __m256i one=_mm256_set1_epi16(1);
			for(i=0;i<d;i+=16){
				__m256i a=_mm256_load_si256((__m256i*)(arr+l+i));
				a=_mm256_cmpgt_epi16(a,x);
				ans=_mm256_add_epi16(ans,_mm256_and_si256(one,a));
			}
			_mm256_store_si256((__m256i*)C, ans);
			for(i=0;i<16;i++){
				a+=C[i];
			}
			for(i=l+d;i<=r;i++){
				a+=arr[i]>c;
			}
			cout<<a<<'\n';
		}
	}
	return 0;
}
