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
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n;
struct str{
    ll a,b,t;
    bool operator<(str&r){
        return a<r.a;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<str>arr(n);
    vector<ll>par(n);
    for(i=0;i<n;i++){
        cin>>arr[i].a;
    }
    for(i=0;i<n;i++){
        cin>>j;
        arr[j-1].t=i+1;
    }
    for(i=0;i<n;i++){
        arr[i].b=arr[arr[i].a-1].t;
    }
//    sort(all(arr));
    vector<ll>brr;
    brr.push_back(0);
//    for(i=0;i<n;i++)cout<<arr[i].b<<' ';
    for(i=0;i<n;i++){
        if(*brr.rbegin()<arr[i].b){
            brr.push_back(arr[i].b);
        }
        else{
            brr[upper_bound(all(brr),arr[i].b)-brr.begin()]=arr[i].b;
        }
    }
    cout<<brr.size()-1;
    return 0;
}
