#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr(ddebug){cout<<"[DEBUG] "<<#x<<" : "<<x<<'\n';}
#define debugc(c) if constexpr(ddebug) {cout << "[DEBUG] "<<#c<<" : "; for(auto &x : c) cout << x << ", "; cout << '\n';}


void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
}

void preprocess(){
    ll i,j;

}

void solve(ll testcase) {
    ll i,j,k;
    ll n,m,s;
    cin>>n;
    vector<ll>arr(n),cnt(1'000'005);
    for(i=0;i<n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    ll st= find_if(cnt.begin(),cnt.end(),[](ll x){return x>0;})-cnt.begin();
    ll en=1'000'005;
    while(--en){
        if(cnt[en])break;
    }
    for(i=st;i<=en;i++){
        if(!cnt[i]){
            cout<<-1;
            return;
        }
    }
    if(st==en){
        if(cnt[st]==1){
            cout<<st;
        }
        else cout<<-1;
        return;
    }
    else{
        auto cnt2=cnt;
        vector<ll>ans;
        bool b=0;
        for(i=st;i<en;i++){
            if(cnt2[i]>cnt2[i+1]+1){
                b=1;
                break;
            }
            else {
                for(j=0;j<cnt2[i]-1;j++){
                    ans.push_back(i);
                    ans.push_back(i+1);
                }
                ans.push_back(i);
                cnt2[i+1]-=cnt2[i]-1;
            }
        }
        if(cnt2[en]==1&&!b){
            ans.push_back(en);
            for(auto k:ans)cout<<k<<' ';
            return;
        }
        else if(cnt2[en]==0&&!b){
            for(auto k:ans)cout<<k<<' ';
            return;
        }
        else{
            cnt2=cnt;
            ans.clear();
            ans.push_back(st+1);
            cnt2[st+1]--;
            b=0;
            for(i=st;i<en;i++){
                if(cnt2[i]>cnt2[i+1]+1){
                    b=1;
                    break;
                }
                else {
                    for(j=0;j<cnt2[i]-1;j++){
                        ans.push_back(i);
                        ans.push_back(i+1);
                    }
                    ans.push_back(i);
                    cnt2[i+1]-=cnt2[i]-1;
                }
            }
            if(cnt2[en]==1&&!b){
                ans.push_back(en);
                for(auto k:ans)cout<<k<<' ';
                return;
            }
            else if(cnt2[en]==0&&!b){
                for(auto k:ans)cout<<k<<' ';
                return;
            }
            else{
                cout<<-1;
                return;
            }
        }
    }
}

int main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}