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
ll n;
vector<vector<ll>>arr;
void star(ll lev, ll x, ll y){
    if(lev%2){
        for(ll i=0;i<(1<<lev)-1;i++){
            arr[x+i][y+(1<<lev)-i-2]=arr[x+i][y+(1<<lev)+i-2]=arr[x+(1<<lev)-2][y+i]=arr[x+(1<<lev)-2][y+i+(1<<lev)-2]='*';
        }
    }else{
        for(ll i=0;i<(1<<lev)-1;i++){
            arr[x+i][y+i]=arr[x][y+i]=arr[x][y+(1<<lev)+i-2]=arr[x+i][y+(2<<lev)-4-i]='*';
        }
    }
    if(lev>1){
        if(lev%2){
            star(lev-1,x+(1<<(lev-1))-1,y+(1<<(lev-1)));
        }else{
            star(lev-1,x+1,y+(1<<(lev-1)));

        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(1<<n,vector<ll>(2<<n));
    star(n,0,0);
    for(i=0;i<(1<<n)-1;i++){
        bool b=0;
        for(j=(2<<n)-1;j>=0;j--){
            if(arr[i][j]=='*')b=1;
            else if(b)arr[i][j]=' ';
        }
    }
    for(i=0;i<(1<<n)-1;i++){
        for(j=0;j<(2<<n);j++){
            if(arr[i][j])cout<<(char)arr[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
