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
bitset<21>arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll m,n;
    cin>>m;
    arr=0;
    while(m--){
        string st;
        cin>>st;
        if(st=="add"){
            cin>>n;
            arr[n]=1;
        }
        else if(st=="remove"){
            cin>>n;
            arr[n]=0;
        }
        else if(st=="check"){
            cin>>n;
            cout<<arr[n]<<'\n';
        }
        else if(st=="toggle"){
            cin>>n;
            arr[n]=!arr[n];
        }
        else if(st=="all"){
            arr.set();
        }
        else if(st=="empty"){
            arr.reset();
        }
    }

    return 0;
}
