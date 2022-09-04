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

deque<ll> arr;
deque<ll> le, ri;
ll n,ans;
void merge_sort(deque<ll>::iterator it,ll st, ll en){
    if(st<en){
        merge_sort(it,st,(st+en)>>1);
        merge_sort(it,((st+en)>>1)+1,en);
        deque<ll> tmp;
        ll i=st,j=1+((st+en)>>1);
        while(i<=((st+en)>>1)&&j<=en){
            if(it[i]<=it[j]){
                tmp.push_back(it[i++]);
            }
            else{
                ans+=((st+en)>>1)-i+1;
                tmp.push_back(it[j++]);
            }
        }
        while(i<=((st+en)>>1)){
            tmp.push_back(it[i++]);
        }
        while(j<=en){
            tmp.push_back(it[j++]);
        }
        for(i=st,j=0;i<=en;i++,j++)it[i]=tmp[j];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        ll t;
        cin>>t;
        arr.pb(t);
    }
    merge_sort(arr.begin(),0,n-1);
    cout<<ans;

    return 0;
}
