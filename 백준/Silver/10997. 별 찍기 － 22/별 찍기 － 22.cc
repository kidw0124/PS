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
char arr[400][400];

void func(int x, int y, int lev){
    if(lev==1){
        arr[x][y]=arr[x][y+1]=arr[x+1][y]=arr[x+2][y]='*';
        return;
    }
    int n=lev,i;
    for(i=0;i<4*n-3;i++){
        arr[x][y+i]=arr[x+i][y]=arr[x+4*n-2][y+i]=arr[x+i+2][y+4*n-4]='*';
    }
    arr[x+i][y]=arr[x+i+1][y]=arr[x][y+4*n-3]='*';
    func(x+2,y+2,lev-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    memset(arr,' ',sizeof(arr));
    arr[1][1]=0;
    if(n==1){
        cout<<"*";
        return 0;
    }
    memset(arr,0,sizeof(arr[1]));
    func(0,0,n);

    for(i=0;i<4*n-1;i++){
        for(j=0;j<4*n-3;j++){
            if(i==1&&j==1)break;
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
//    for(i=0)
    return 0;
}
