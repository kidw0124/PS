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
const ll MN=100000+5;
vector<ll> data[MN];
bitset<MN> arr,brr,crr;
ll n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int t;
        cin>>t;
        for(j=0;j<t;j++){
            ll k;
            cin>>k;
            data[i].push_back(k);
        }
    }
    for(i=1;i<=n;i++){
        int t;
        cin>>t;
        arr[i]=t;
        brr[i]=arr[i];
    }
    for(i=m-1;i>=0;i--){
        bool c=0;
        for(j=0;j<data[i].size();j++){
            if(!arr[data[i][j]])c=1;
        }
        if(c){
            for(j=0;j<data[i].size();j++){
                arr[data[i][j]]=0;
            }
        }
    }
    crr=arr;

    for(i=0;i<m;i++){
        bool c=0;
        for(j=0;j<data[i].size();j++){
            if(crr[data[i][j]])c=1;
        }
        if(c){
            for(j=0;j<data[i].size();j++){
                crr[data[i][j]]=1;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(brr[i]!=crr[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";

    for(i=1;i<=n;i++){
        cout<<arr[i]<<' ';
    }


    return 0;
}
