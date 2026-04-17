#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll n,m;
vector<set<char>>arr({{'E','I'},{'S','N'},{'T','F'},{'P','J'}});
vector<string>str;

int anses(ll x, ll y){
    int ret=0,i;
    if(x+3<n){
        if(y+3<m){
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x+i][y+i])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
        {
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x+i][y])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
        if(y-3>=0){
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x+i][y-i])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
    }
    if(x-3>=0){
        if(y+3<m){
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x-i][y+i])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
        {
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x-i][y])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
        if(y-3>=0){
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x-i][y-i])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
    }
    {
        if(y+3<m){
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x][y+i])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
        if(y-3>=0){
            bool c=0;
            for(i=0;i<4;i++){
                if(arr[i].find(str[x][y-i])==arr[i].end())c=1;
            }
            if(!c)ret++;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    ll ans=0;
    str.resize(n);
    for(i=0;i<n;i++)cin>>str[i];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ans+=anses(i,j);
        }
    }
    cout<<ans;
    return 0;
}
