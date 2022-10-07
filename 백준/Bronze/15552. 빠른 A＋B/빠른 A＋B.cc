#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <immintrin.h>
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

alignas(16) short A[16]{ 1, 2, 3, 1, 2, 3, 1, 2 };
alignas(16) short B[16]{ 1, 2, 3, 4, 5, 6, 7, 8 };
alignas(16) short C[16];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	ll t;
	cin>>t;
	int td16=t/16,tm16=t%16;
	for(int i=0;i<td16;i++){
		for(int j=0;j<16;j++){
			cin>>A[j]>>B[j];
		}
		__m256i a = _mm256_load_si256((__m256i*)A);
		__m256i b = _mm256_load_si256((__m256i*)B);
		__m256i c = _mm256_add_epi16(a, b);
		_mm256_store_si256((__m256i*)C, c);
		for (int j = 0; j < 16; j++) cout << C[j] << '\n';
	}
	for(int i=0;i<tm16;i++){
		cin>>A[i]>>B[i];
	}
	__m256i a = _mm256_load_si256((__m256i*)A);
	__m256i b = _mm256_load_si256((__m256i*)B);
	__m256i c = _mm256_add_epi16(a, b);
	_mm256_store_si256((__m256i*)C, c);
	for (int j = 0; j < tm16; j++) cout << C[j] << '\n';
	return 0;
}
