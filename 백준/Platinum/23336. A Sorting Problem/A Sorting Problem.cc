#include<bits/stdc++.h>
using namespace std;
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

ostream& operator<<(ostream&os,pll x){
    os<<"{"<<x.first<<","<<x.second<<"}";
}

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

void mmerge(vector<ll>&arr, ll l, ll mid, ll r, ll&cnt){
    vector<ll>tmp;
    ll x=l,y=mid;
    while(x<mid&&y<r){
        if(arr[x]<=arr[y]){
            tmp.push_back(arr[x++]);
        }
        else{
            cnt+=mid-x;
            tmp.push_back(arr[y++]);
        }
    }
    while(y<r){
        tmp.push_back(arr[y++]);
    }
    while(x<mid){
        tmp.push_back(arr[x++]);
    }
    copy(tmp.begin(),tmp.end(),arr.begin()+l);
}

void msort(vector<ll>&arr, ll l, ll r, ll&cnt){
    if(l+1>=r){
        return;
    }
    else{
        ll mid=(l+r)>>1;
        msort(arr,l,mid,cnt);
        msort(arr,mid,r,cnt);
        mmerge(arr,l,mid,r,cnt);
    }
}

ll merge_sort(vector<ll>arr){
    ll cnt=0;
    msort(arr,0,arr.size(),cnt);
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<merge_sort(arr);

    return 0;
}