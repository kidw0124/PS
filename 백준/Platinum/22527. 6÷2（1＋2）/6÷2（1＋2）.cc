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

vector<vector<set<ll>>>dp;
ll n;
vector<ll>arr;
string str;
map<ll,ll>paren;

void solve(ll st, ll en){
    if(!dp[st][en].empty()){
        return;
    }
    else if(str[st]=='('&&str[en-1]==')'&&paren[st]==en-1){
        solve(st+1,en-1);
        dp[st][en]=dp[st+1][en-1];
    }
    else{
        ll i,j;
        for(i=st;i<en;i++){
            if(isdigit(str[i]))continue;
            else break;
        }
        if(i==en){
            dp[st][en]={stoll(str.substr(st,en-st))};
            return;
        }
        else{
            for(i=st;i<en;i++){
                if((arr[i]==arr[en-1])){
                    if(str[i]=='+'){
                        solve(st,i);
                        solve(i+1,en);
                        for(auto k:dp[st][i]){
                            for(auto kk:dp[i+1][en]){
                                dp[st][en].insert(k+kk);
                            }
                        }
                    }
                    else if(str[i]=='-'){
                        solve(st,i);
                        solve(i+1,en);
                        for(auto k:dp[st][i]){
                            for(auto kk:dp[i+1][en]){
                                dp[st][en].insert(k-kk);
                            }
                        }
                    }
                    else if(str[i]=='*'){
                        solve(st,i);
                        solve(i+1,en);
                        for(auto k:dp[st][i]){
                            for(auto kk:dp[i+1][en]){
                                dp[st][en].insert(k*kk);
                            }
                        }
                    }
                    else if(str[i]=='/'){
                        solve(st,i);
                        solve(i+1,en);
                        for(auto k:dp[st][i]){
                            for(auto kk:dp[i+1][en]){
                                if(kk){
                                    ll res=abs(k)/abs(kk);
                                    if(k*kk>=0) {
                                        dp[st][en].insert(res);
                                    }
                                    else{
                                        dp[st][en].insert(-res);

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    setup();
    ll i,j;
    while(getline(cin,str),str!="#"){
        dp.clear();
        arr.clear();
        n=str.size();
        dp.resize(n+1,vector<set<ll>>(n+1));
        arr.resize(n);
        stack<ll>stk;
        for(i=0;i<n;i++){
            arr[i]=i?arr[i-1]:0;
            if(str[i]=='(')arr[i]++,stk.push(i);
            else if(str[i]==')')arr[i]--,paren[stk.top()]=i,stk.pop();
        }
        solve(0,n);
//        for(auto k:dp){
//            for(auto kk:k){
//                cout<<"{";
//                for(auto kkk:kk){
//                    cout<<kkk<<", ";
//                }
//                cout<<"},   \t";
//            }
//            cout<<"\n";
//        }
        cout<<dp[0][n].size()<<'\n';
    }
}