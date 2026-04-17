#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using LL = __int128;
using ld = long double;
using pll = pair<ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif


void solve(ll testcase){
    ll i,j;
    ll a,b;
    cin>>a>>b;
    if(!a)return;
    auto comb3=[](LL x)->LL{
        if(x<3)return 0;
        return x*(x-1)*(x-2)/6;
    };
    auto counting=[&comb3](ll x, ll y){
        LL cnt=(x+1)*(y+1);
        LL ret=comb3(cnt);
        ret-=(comb3(cnt-x-1)+comb3(cnt-y-1))*2;
        ret+=comb3(cnt-x-x-2)+comb3(cnt-y-y-2);
        ret+=comb3(cnt-x-y-1)*4;
        ret-=(comb3(cnt-x-x-y-1)+comb3(cnt-y-y-x-1))*2;
        ret+=comb3(cnt-x-x-y-y);
        ll g=gcd(x,y);
        ret-=(g-1)*2;
        return ret;
    };
//    auto counting2=[&comb3](ll x, ll y){
//        return (x-1)*(y-1)*4
//                +(x-1)*2+(y-1)*2+(x-1+x-1+y-1+y-1)*2
//                +4;
//    };
    LL ans=0;
//    cout<<(ll)counting(3,3)<<'\n';
//    cout<<(ll)counting(2,3)<<'\n';
//    cout<<(ll)counting(3,2)<<'\n';
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            ans+=counting(i,j)*(a-i+1)*(b-j+1);
        }
    }
    cout<<"Case "<<testcase<<": "<<(ll)ans<<'\n';
    solve(testcase+1);
}

int main(){

#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t st = clock();
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t = 1;
//    cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
