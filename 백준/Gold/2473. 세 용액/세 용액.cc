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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vl arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll a=1e11;
    vector<ll>num(3);
    for(i=0;i<n-2;i++){
        ll st=i+1,en=n-1;
        ll k=arr[i]+arr[st]+arr[en];
        vector<ll>temp({i,st,en});
        while(st<en){
            if(abs(k)>abs(arr[i]+arr[st]+arr[en])){
                k=arr[i]+arr[st]+arr[en];
                temp={i,st,en};
            }
            if(arr[i]+arr[st]+arr[en]>0)en--;
            else st++;
        }
        if(abs(a)>abs(k))a=k,num=temp;
    }
    cout<<arr[num[0]]<<' '<<arr[num[1]]<<' '<<arr[num[2]];
    return 0;
}
