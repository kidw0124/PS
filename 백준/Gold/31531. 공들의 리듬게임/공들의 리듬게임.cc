#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using pll = pair<ll,ll>;

using ld = long double;

using pld = pair<ld,ld>;

typedef unsigned long long ull;

#pragma warning(disable : 4996)

#pragma comment(linker, "/STACK:336777216")

#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx,avx2,fma")

#define pb(x) push_back(x)

#define all(x) (x).begin(), (x).end()

#define rep(i, a, b) for (auto i = (a); i < (b); i++)

#define each(x, a) for (auto &x : a)

#ifdef kidw0124

constexpr bool ddebug = true;

#else

constexpr bool ddebug = false;

#endif

#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124

const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE

#else

const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE

#endif

const ll mod = 1e9+7;

void setup()

{

    if(ddebug) {

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    }

    else {

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cout.tie(0);

    }

}

void preprocess() {

    ll i, j;

}

struct ball{

    ll a,d;

    bool operator<(const ball &r) const{

        return a<r.a;

    }

};

void solve(ll testcase){

    ll i,j,k;

    ll n;

    cin>>n;

    vector<ball> arr(n);

    for(i=0;i<n;i++){

        cin>>arr[i].a>>arr[i].d;

    }

    sort(all(arr));

    ll ans=0;

    ll cnt1=0, cnt2=0;

    for(i=0;i<n;i++){

        if(arr[i].d<0){

            ans+=cnt1+2*cnt2;

        }

        else if(arr[i].d==0){

            cnt2++;

            ans+=2*cnt1;

        }

        else{

            cnt1++;

        }

    }

    cnt1=0, cnt2=0;

    for(i=n-1;i>=0;i--){

        if(arr[i].d<0){

            cnt1++;

        }

        else if(arr[i].d==0){

            cnt2++;

            ans+=2*cnt1;

        }

        else{

            ans+=cnt1+2*cnt2;

        }

    }

    cout<<ans/2<<'\n';

}

int main()

{

    setup();

    preprocess();

    ll t = 1;

//    cin >> t;

    for (ll testcase = 1; testcase <= t; testcase++)

    {

        solve(testcase);

    }

    return 0;

}