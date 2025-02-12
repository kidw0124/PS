#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
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
#define endl '\n'
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

void solve(ll testcase){
    int i,j,k;
    ll n,m;
    cin >> n >> m;
    if(n==1){
        cout<<"0\n"
              "0\n";
        return;
    }
    vector<ll>arr(n),brr(n-1);
    vector<pll>crr_rng(n-1);
    for(i=0;i<n;i++) {
        cin >> arr[i];
        if(i){
            brr[i-1] = arr[i] - arr[i-1];
            crr_rng[i-1] = {-m-brr[i-1],m-brr[i-1]};
        }
    }
    if(n==2){
        if(arr[0]<arr[1]-m){
            cout<<arr[1]-m-arr[0]<<'\n';
            cout<<arr[1]-m-arr[0]<<" 0\n";
        }
        else if(arr[1]+m<arr[0]){
            cout<<arr[0]-arr[1]-m<<'\n';
            cout<<"0 "<<arr[0]-arr[1]-m<<'\n';
        }
        else{
            cout<<"0\n0 0\n";
        }
        return;
    }
    ll ans=1e18;
    vector<ll>ans_arr(n);
    {
        ll st=crr_rng[0].first,en=crr_rng[0].second;
        if(abs(st)%2==1)st++;
        if(abs(en)%2==1)en--;
        st/=2,en/=2;
        while(st<=en){
            ll mid=(st+en)/2*2;
            bool pos=true;
            vector<ll>tmp(n-1);
            ll now=tmp[0]=mid;
            for(i=1;i<n-1;i++){
                now=min(now,crr_rng[i].second);
                if(abs(now)%2!=abs(mid)%2)now--;
                if(now<crr_rng[i].first){
                    pos=false;
                    break;
                }
                tmp[i]=now;
            }
            if(tmp[n-2]<-mid)pos=false;
            if(mid<ans && pos){
                for(i=1;i<n-1;i++){
                    ans_arr[i]=(tmp[i-1]-tmp[i])>>1;
                }
                ans_arr[0]=0;
                ans_arr[n-1]=(tmp[n-2]+tmp[0])>>1;
                ans=mid;
            }
            if(pos)en=mid/2-1;
            else st=mid/2+1;
        }
        st=crr_rng[0].first,en=crr_rng[0].second;
        if(abs(st)%2==0)st++;
        if(abs(en)%2==0)en--;
        st=(st-1)/2,en=(en-1)/2;
        while(st<=en){
            ll mid=(st+en)/2*2+1;
            bool pos=true;
            vector<ll>tmp(n-1);
            ll now=tmp[0]=mid;
            for(i=1;i<n-1;i++){
                now=min(now,crr_rng[i].second);
                if(abs(now)%2!=abs(mid)%2)now--;
                if(now<crr_rng[i].first){
                    pos=false;
                    break;
                }
                tmp[i]=now;
            }
            if(tmp[n-2]<-mid)pos=false;
            if(mid<ans && pos){
                for(i=1;i<n-1;i++){
                    ans_arr[i]=(tmp[i-1]-tmp[i])>>1;
                }
                ans_arr[0]=0;
                ans_arr[n-1]=(tmp[n-2]+tmp[0])>>1;
                ans=mid;
            }
            if(pos)en=(mid-1)/2-1;
            else st=(mid-1)/2+1;
        }
    }
    {
        ll st=-crr_rng[n-2].second,en=-crr_rng[n-2].first;
        if(abs(st)%2==1)st++;
        if(abs(en)%2==1)en--;
        st/=2,en/=2;
        while(st<=en){
            ll mid=(st+en)/2*2;
            bool pos=true;
            vector<ll>tmp(n-1);
            ll now=tmp[n-2]=mid;
            for(i=0;i<n-2;i++){
                now=min(now,crr_rng[i].second);
                if(abs(now)%2!=abs(mid)%2)now--;
                if(now<crr_rng[i].first){
                    pos=false;
                    break;
                }
                tmp[i]=now;
            }
            if(tmp[n-3]<-mid)pos=false;
            if(mid<ans && pos){
                tmp[n-2]=-mid;
                for(i=1;i<n-1;i++){
                    ans_arr[i]=(tmp[i-1]-tmp[i])>>1;
                }
                ans_arr[0]=-(tmp[n-2]+tmp[0])>>1;
                ans_arr[n-1]=0;
                ans=mid;
            }
            if(pos)en=mid/2-1;
            else st=mid/2+1;
        }
        st=-crr_rng[n-2].second,en=-crr_rng[n-2].first;
        if(abs(st)%2==0)st++;
        if(abs(en)%2==0)en--;
        st=(st-1)/2,en=(en-1)/2;
        while(st<=en){
            ll mid=(st+en)/2*2+1;
            bool pos=true;
            vector<ll>tmp(n-1);
            ll now=tmp[n-2]=mid;
            for(i=0;i<n-2;i++){
                now=min(now,crr_rng[i].second);
                if(abs(now)%2!=abs(mid)%2)now--;
                if(now<crr_rng[i].first){
                    pos=false;
                    break;
                }
                tmp[i]=now;
            }
            if(tmp[n-3]<-mid)pos=false;
            if(mid<ans && pos){
                tmp[n-2]=-mid;
                for(i=1;i<n-1;i++){
                    ans_arr[i]=(tmp[i-1]-tmp[i])>>1;
                }
                ans_arr[0]=-(tmp[n-2]+tmp[0])>>1;
                ans_arr[n-1]=0;
                ans=mid;
            }
            if(pos)en=(mid-1)/2-1;
            else st=(mid-1)/2+1;
        }
    }
    if(ans==1e18){
        cout<<"-1\n";
        return;
    }
    cout<<ans<<'\n';
    for(i=0;i<n;i++){
        cout<<ans_arr[i]<<" ";
    }


}

void setup() {
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
    ll i, j, k;

}

signed main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
#ifdef kidw0124
    clock_t st = clock();
#endif
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
#ifdef kidw0124
    cout << "\n\nTime: " << (clock() - st) * 1.0 / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}