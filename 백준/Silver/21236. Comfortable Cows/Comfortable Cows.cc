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

vector<vector<int>>arr(1050,vector<int>(1050,0));
vector<vector<bool>>chk(1050,vector<bool>(1050,false));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    int n,cnt=0;
    cin>>n;
    for(i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        t1+=10;t2+=10;
        arr[t1-1][t2]++;
        arr[t1+1][t2]++;
        arr[t1][t2-1]++;
        arr[t1][t2+1]++;
        if(chk[t1-1][t2]&&arr[t1-1][t2]==3)cnt++;
        if(chk[t1-1][t2]&&arr[t1-1][t2]==4)cnt--;
        if(chk[t1+1][t2]&&arr[t1+1][t2]==3)cnt++;
        if(chk[t1+1][t2]&&arr[t1+1][t2]==4)cnt--;
        if(chk[t1][t2-1]&&arr[t1][t2-1]==3)cnt++;
        if(chk[t1][t2-1]&&arr[t1][t2-1]==4)cnt--;
        if(chk[t1][t2+1]&&arr[t1][t2+1]==3)cnt++;
        if(chk[t1][t2+1]&&arr[t1][t2+1]==4)cnt--;
        if(arr[t1][t2]==3)cnt++;
        chk[t1][t2]=true;
        cout<<cnt<<'\n';
    }

    return 0;
}
