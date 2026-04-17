#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void solve(ll testcase){
    int i,j;
    ll n,sum=0;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i],sum+=arr[i];
    }
    if(sum&1){
        cout<<"no quotation\n";
    }
    else if(sum==2){
        cout<<1;
    }
    else{
        ll maxi=0;
        while(maxi*(maxi+1)/2<sum)maxi++;
        while(--maxi>1){
            auto tmp=arr;
            ll st=0,en=n-1;
            for(i=maxi;i>0;i--){
                if(tmp[st]==0)st++;
                if(tmp[st]<i)break;
                tmp[st]-=i;
                if(tmp[en]==0)en--;
                if(tmp[en]<i)break;
                tmp[en]-=i;
            }
            if(st<=en && !i){
                cout<<maxi<<"\n";
                return;
            }
        }
        cout<<"no quotation\n";
    }


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
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
