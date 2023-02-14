#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
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
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

void rotate(ll&a, ll&b, ll&c, ll&d) {
    swap(a, b);
    swap(a, c);
    swap(a, d);
}
void rotate_r(ll&a, ll&b, ll&c, ll&d) {
    swap(a, d);
    swap(a, c);
    swap(a, b);
}
void U(vector<ll>&arr){
    rotate(arr[1],arr[3],arr[9],arr[7]);
    rotate(arr[2],arr[6],arr[8],arr[4]);
    rotate(arr[10],arr[30],arr[39],arr[13]);
    rotate(arr[28],arr[37],arr[15],arr[12]);
    rotate(arr[11],arr[29],arr[38],arr[14]);
}

void u(vector<ll>&arr){
    rotate_r(arr[1],arr[3],arr[9],arr[7]);
    rotate_r(arr[2],arr[6],arr[8],arr[4]);
    rotate_r(arr[10],arr[30],arr[39],arr[13]);
    rotate_r(arr[28],arr[37],arr[15],arr[12]);
    rotate_r(arr[11],arr[29],arr[38],arr[14]);
}

void L(vector<ll>&arr){
    rotate(arr[10],arr[12],arr[24],arr[22]);
    rotate(arr[11],arr[18],arr[23],arr[16]);
    rotate(arr[1],arr[13],arr[54],arr[34]);
    rotate(arr[7],arr[25],arr[52],arr[28]);
    rotate(arr[4],arr[19],arr[53],arr[31]);
}

void l(vector<ll>&arr){
    rotate_r(arr[10],arr[12],arr[24],arr[22]);
    rotate_r(arr[11],arr[18],arr[23],arr[16]);
    rotate_r(arr[1],arr[13],arr[54],arr[34]);
    rotate_r(arr[7],arr[25],arr[52],arr[28]);
    rotate_r(arr[4],arr[19],arr[53],arr[31]);
}

void R(vector<ll>&arr){
    rotate(arr[37],arr[43],arr[45],arr[39]);
    rotate(arr[38],arr[40],arr[44],arr[42]);
    rotate(arr[3],arr[36],arr[48],arr[15]);
    rotate(arr[9],arr[30],arr[46],arr[27]);
    rotate(arr[6],arr[33],arr[47],arr[21]);
}

void r(vector<ll>&arr){
    rotate_r(arr[37],arr[43],arr[45],arr[39]);
    rotate_r(arr[38],arr[40],arr[44],arr[42]);
    rotate_r(arr[3],arr[36],arr[48],arr[15]);
    rotate_r(arr[9],arr[30],arr[46],arr[27]);
    rotate_r(arr[6],arr[33],arr[47],arr[21]);
}

void F(vector<ll>&arr){
    rotate(arr[13],arr[15],arr[27],arr[25]);
    rotate(arr[14],arr[21],arr[26],arr[19]);
    rotate(arr[7],arr[39],arr[48],arr[24]);
    rotate(arr[9],arr[45],arr[54],arr[12]);
    rotate(arr[8],arr[42],arr[51],arr[18]);
}

void f(vector<ll>&arr){
    rotate_r(arr[13],arr[15],arr[27],arr[25]);
    rotate_r(arr[14],arr[21],arr[26],arr[19]);
    rotate_r(arr[7],arr[39],arr[48],arr[24]);
    rotate_r(arr[9],arr[45],arr[54],arr[12]);
    rotate_r(arr[8],arr[42],arr[51],arr[18]);
}

void D(vector<ll>&arr){
    rotate(arr[46],arr[52],arr[54],arr[48]);
    rotate(arr[49],arr[53],arr[51],arr[47]);
    rotate(arr[25],arr[45],arr[36],arr[22]);
    rotate(arr[27],arr[43],arr[34],arr[24]);
    rotate(arr[26],arr[44],arr[35],arr[23]);
}

void d(vector<ll>&arr){
    rotate_r(arr[46],arr[52],arr[54],arr[48]);
    rotate_r(arr[49],arr[53],arr[51],arr[47]);
    rotate_r(arr[25],arr[45],arr[36],arr[22]);
    rotate_r(arr[27],arr[43],arr[34],arr[24]);
    rotate_r(arr[26],arr[44],arr[35],arr[23]);
}

void B(vector<ll>&arr){
    rotate(arr[30],arr[28],arr[34],arr[36]);
    rotate(arr[29],arr[31],arr[35],arr[33]);
    rotate(arr[1],arr[22],arr[46],arr[37]);
    rotate(arr[3],arr[10],arr[52],arr[43]);
    rotate(arr[2],arr[16],arr[49],arr[40]);
}

void b(vector<ll>&arr){
    rotate_r(arr[30],arr[28],arr[34],arr[36]);
    rotate_r(arr[29],arr[31],arr[35],arr[33]);
    rotate_r(arr[1],arr[22],arr[46],arr[37]);
    rotate_r(arr[3],arr[10],arr[52],arr[43]);
    rotate_r(arr[2],arr[16],arr[49],arr[40]);
}

ll find_per(vector<ll>&arr,ll x){
    ll ret=1;
    ll org=x;
    x=arr[x];
    while(org!=x){
        x=arr[x];
        ret++;
    }
    return ret;
}

int main() {
    setup();
    string str;
    while(getline(cin,str)){
        vector<ll>arr(55);
        iota(all(arr),0);
        for(auto k:str){
            switch (k) {
                case 'R':
                    R(arr);
                    break;
                case 'r':
                    r(arr);
                    break;
                case 'B':
                    B(arr);
                    break;
                case 'b':
                    b(arr);
                    break;
                case 'F':
                    F(arr);
                    break;
                case 'f':
                    f(arr);
                    break;
                case 'U':
                    U(arr);
                    break;
                case 'l':
                    l(arr);
                    break;
                case 'D':
                    D(arr);
                    break;
                case 'd':
                    d(arr);
                    break;
                case 'L':
                    L(arr);
                    break;
                case 'u':
                    u(arr);
                    break;
            }
        }
        vector<ll>per(55);
        ll ans=per[1]= find_per(arr,1);
        for(ll i=2;i<55;i++){
            ans=lcm(ans, per[i]=find_per(arr,i));
        }
        debugc(arr);
        debugc(per);
        cout<<ans<<'\n';
    }
}