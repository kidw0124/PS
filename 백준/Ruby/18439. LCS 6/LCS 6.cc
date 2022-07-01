#define private public
#include<bitset>
#undef private
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
const int MX=50000+5;
const int alpha_num=26;
#include <x86intrin.h>

template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for(int i=0, c=0; i<_Nw; i++)
		c=_subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
}
template<> void _M_do_sub(_Base_bitset<1> &A, const _Base_bitset<1> &B) {
	A._M_w-=B._M_w;
}
template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb> &A, const bitset<_Nb> &B) {
	_M_do_sub(A, B);
	return A;
}
template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B) {
	bitset<_Nb> C(A);
	return C-=B;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string a,b;
    vector<bitset<MX>>S(alpha_num,bitset<MX>());
    bitset<MX>D,x;
    cin>>a>>b;
    for(i=0;i<b.size();i++){
        S[b[i]-'A'][i]=1;
    }
    for(i=0;i<a.size();i++){
        x=D|S[a[i]-'A'];
        D<<=1;
        D|=1;
        D=x&(x^(x-D));
    }
    cout<<D.count();

    return 0;
}
