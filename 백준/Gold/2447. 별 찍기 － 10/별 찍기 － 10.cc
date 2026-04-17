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

int n;
char arr[7000][7000];

void func(int a, int b, int lev){
    if(lev==0){
        arr[a][b]='*';
        return;
    }
    else{
        ll p=pow(3,lev-1);
        func(a,b,lev-1);
        func(a+p,b,lev-1);
        func(a+2*p,b,lev-1);
        func(a,b+p,lev-1);
        func(a+2*p,b+p,lev-1);
        func(a,b+2*p,lev-1);
        func(a+p,b+2*p,lev-1);
        func(a+2*p,b+2*p,lev-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr[i][j]=' ';
        }
    }
    ll lev=1,t=3;
    while(t!=n){
        t*=3;
        lev++;
    }
    func(0,0,lev);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
