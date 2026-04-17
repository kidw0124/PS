#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    int n;
    cin>>n;
    vector<vector<int>> grp(n,vector<int>(n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>grp[i][j];
        }
    }
    int a=1000000000;
    vector<vector<int>>dp(n,vector<int>(1<<n,1000000000));
    stack<pair<int,int>>st;
    dp[0][1]=0;
    st.push({0,1});
    while(!st.empty()){
        ll nowv=st.top().first,nowe=st.top().second;
        ll nowt=dp[nowv][nowe];
        st.pop();
        for(i=0;i<n;i++){
            if(grp[nowv][i]==0||(i!=0&&((nowe>>i)&1)))continue;
            else{
                if(nowt+grp[nowv][i]<dp[i][nowe|(1<<i)]){
                    dp[i][nowe|(1<<i)]=nowt+grp[nowv][i];
                    st.push({i,nowe|(1<<i)});
                }
            }
        }
    }
    a=dp[0][(1<<n)-1];
    cout<<a;
    return 0;
}
