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
string s;
ll n;
ll arr[9][2]={1,2,3,0,4,3,3,3,5,3,5,6,1,7,8,7,5,0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    while(n--){
        cin>>s;
        ll a=0;
        for(j=0;j<s.size();j++){
            a=arr[a][s[j]-'0'];
        }
        if(a==0||a==6||a==7)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
