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
ll n,m;
vector<deque<ll>> arr;
vector<ll> brr,crr;
vector<ll> chk;

ll dfs_con(ll);

ll dfs(ll a){
    ll i=0,j=0, cnt=0;
    for(i=0;i<arr[a].size();i++){
        if(!brr[arr[a][i]]){
            cnt++;
            brr[arr[a][i]]=a;
        }
        if(cnt==2)break;
    }
    if(i!=arr[a].size())return cnt;
    else{
        chk[a]=2;
        for(i=crr[a];i<arr[a].size();i++){
            if(chk[brr[arr[a][i]]]==2||brr[arr[a][i]]==a)continue;
            else{
                ll t=brr[arr[a][i]];
                brr[arr[a][i]]=a;
                chk[t]++;
                if(dfs_con(t)){
                    cnt++;
                }
                else{
                    brr[arr[a][i]]=t;
                }
                if(cnt==2)break;
            }
        }
        crr[a]=max(crr[a],i);
        return cnt;
    }
}

ll dfs_con(ll a){
    ll i=0,j=0,cnt=0;
    for(i=0;i<arr[a].size();i++){
        if(!brr[arr[a][i]]){
            cnt++;
            brr[arr[a][i]]=a;
        }
        if(cnt==1)break;
    }
    if(i!=arr[a].size())return cnt;
    else{
        for(i=crr[a];i<arr[a].size();i++){
            if(chk[brr[arr[a][i]]]==2||brr[arr[a][i]]==a)continue;
            else{
                ll t=brr[arr[a][i]];
                brr[arr[a][i]]=a;
                chk[t]++;
                if(dfs_con(t)){
                    cnt++;
                }
                else{
                    brr[arr[a][i]]=t;
                }
                if(cnt==1)break;
            }
        }
        crr[a]=max(crr[a],i);
        return cnt;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    arr.resize(n+1);
    brr.resize(m+1);
    crr.resize(n+1);
    for(i=1;i<=n;i++){
        ll t;
        cin>>t;
        for(j=0;j<t;j++){
            ll x;
            cin>>x;
            arr[i].push_back(x);
        }
    }
    ll ans=0;
    for(i=1;i<=n;i++){
        chk.clear();
        chk.resize(n+1);
        ans+=dfs(i);
    }
    cout<<ans;
    return 0;
}
