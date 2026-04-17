#include<bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

const ll mod=243*243*243;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    LL n;
    cin>>n;
    vector<ll>ans(n+1);
    ans[1]=45;
    if(n==1){
        cout<<45;
        return 0;
    }
    vector<vector<ll>>pre(n/2+1,vector<ll>(9*n+1)),post(n/2+1,vector<ll>(9*n+1));
    vector<vector<ll>>spre(n/2+1,vector<ll>(9*n+1)),spost(n/2+1,vector<ll>(9*n+1));
    for(i=0;i<10;i++){
        pre[1][i]=post[1][i]=1;
        spre[1][i]=spost[1][i]=i;
    }
    pre[1][0]=0;
    ll now=10;
    for(i=2;i<n/2+1;i++){
        for(j=0;j<9*i+1;j++){
            for(ll k=1;k<min(j+1,(ll)10);k++){
                pre[i][j]+=post[i-1][j-k];
                spre[i][j]+=spost[i-1][j-k];
                spre[i][j]+=k*now*post[i-1][j-k];
                pre[i][j]%=mod;
                spre[i][j]%=mod;
            }
            for(ll k=0;k<min(j+1,(ll)10);k++){
                post[i][j]+=post[i-1][j-k];
                spost[i][j]+=spost[i-1][j-k];
                spost[i][j]+=k*now*post[i-1][j-k];
                post[i][j]%=mod;
                spost[i][j]%=mod;
            }
        }
        now*=10;
        now%=mod;
    }
    now=1;
    for(i=2;i<=n;i++){
        for(j=1;j<pre[i/2].size();j++){
            ans[i]+=pre[i/2][j]*spost[i/2][j];
            ans[i]%=mod;
            ans[i]+=spre[i/2][j]*post[i/2][j]*now*10;
            ans[i]%=mod;
        }
        if(i&1){
            ans[i]*=10;
            ans[i]%=mod;
            for(j=1;j<pre[i/2].size();j++){
                ans[i]+=pre[i/2][j]*post[i/2][j]*now*45;
                ans[i]%=mod;
            }
        }
        else{
            now*=10;
            now%=mod;
        }
    }
    LL answer=0;
    for(i=1;i<=n;i++){
        answer+=ans[i];
        answer%=mod;
    }
    cout<<answer;
    return 0;
}
