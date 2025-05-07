#include<bits/stdc++.h>

#pragma comment(linker, "/STACK:336777216")

#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx,avx2,fma")

using namespace std;

using ll = long long;

using LL = __int128;

using pll = pair<ll, ll>;

using ld = long double;

using pld = pair<ld, ld>;

ld integrate(ld t, ld r){

    return atanh(t/r);

}

void solve() {

    ll i, j;

    pll a, b;

    cin >> a.first >> a.second >> b.first >> b.second;

    if (a.second > b.second)swap(a, b);

    if (a.first > b.first)swap(a.first, b.first);

    if (a.first == b.first) {

        cout <<fixed<< log((ld) b.second / a.second) << '\n';

    }

    else{

        ld x0=(ld)(a.first+b.first)/2+(ld)(b.second-a.second)/(b.first-a.first)*(a.second+b.second)/2;

        ld r=sqrt((x0-a.first)*(x0-a.first)+a.second*a.second);

        cout<<fixed<<integrate(b.first-x0,r)-integrate(a.first-x0,r)<<'\n';

    }

}

int main() {

#ifdef kidw0124

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    clock_t beg = clock();

#else

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

#endif

//    preprocess();

    ll t=1;

    cin>>t;

    while(t--)solve();

#ifdef kidw0124

    cout<<clock()-beg<<"ms\n";

#endif

}