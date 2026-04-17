#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using ld = long double;

typedef unsigned long long ull;

using pll = pair<ll,ll>;

using tlll = tuple<ll,ll,ll>;

using vl = vector<ll>;

using pld = pair<ld,ld>;

using LD = __float128;

using LL = __int128;

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

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

void yes(){

    cout<<"Yes\n";

}

void YES(){

    cout<<"YES\n";

}

void no(){

    cout<<"No\n";

}

void NO(){

    cout<<"NO\n";

}

void preprocess(){

}

void solve() {

    int i,j;

    int n,m,k;

    cin>>n>>m>>k;

    vector<unordered_map<string,ll>>vct(m);

    for(i=0;i<n;i++){

        string s;

        cin>>s;

        for(j=0;j<m;j++){

            vct[j][s.substr(0,j+1)]++;

        }

    }

    for(i=0;i<m;i++){

        for(auto &[s,c]:vct[i]){

            if(c<=k){

                cout<<i+1<<'\n';

                for(auto p:s){

                    cout<<(p=='R'?'S':p=='S'?'P':'R');

                }

                cout<<'\n';

                return;

            }

        }

    }

    cout<<"-1\n";

}

int main() {

#ifdef kidw0124

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    clock_t st=clock();

#else

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

#endif

    preprocess();

    ll t=1;

//    cin>>t;

    while(t--)solve();

#ifdef kidw0124

    debug<<clock()-st<<"ms\n";

#endif

}

