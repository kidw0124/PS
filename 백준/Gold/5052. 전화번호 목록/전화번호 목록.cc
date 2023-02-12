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
#define rep(i,a,b) for(auto (i)=(a);(i)<(b);(i)++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll T,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>T;
    while(T--){
        cin>>n;
        getline(cin,*(new string()));
        vector<string> arr(n);
        rep(i,0,n){
            getline(cin,arr[i]);
            while(arr[i].find(" ")+1){
                arr[i]=arr[i].substr(0,arr[i].find(" "))+arr[i].substr(arr[i].find(" ")+1);
            }
        }
        if(n==1){
            cout<<"YES\n";
            continue;
        }
        sort(all(arr));
        rep(i,0,n-1){
            if(arr[i+1].substr(0,arr[i].size())==arr[i]){
                cout<<"NO\n";break;
            }
            if(i==n-2)cout<<"YES\n";
        }
    }

    return 0;
}
