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
ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b) {
    if(a&&b)return a*(b/gcd(a,b));
    return a+b;
}
ll POW(ll a, ll b, ll rem) {
    ll p=1;
    for(; b; b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;
    return p;
}
vector<pll> arr;
vl lis;
int it[100005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    for(i=0; i<n; i++) {
        pll t;
        cin>>t.first>>t.second;
        arr.pb(t);
    }
    sort(arr.begin(),arr.end());
    lis.pb(arr[0].second);
    it[0]=0;
    for(i=1; i<n; i++) {
        if(lis.back()<arr[i].second) {
            lis.pb(arr[i].second);
            it[i]=lis.size()-1;
        }
        else {
            it[i]=lower_bound(lis.begin(),lis.end(),arr[i].second)-lis.begin();
            *lower_bound(lis.begin(),lis.end(),arr[i].second)=arr[i].second;
        }
    }
    cout<<n-lis.size()<<'\n';
    ll m=lis.size()-1;
    stack<int>st;
    for(i=n-1; i>=0; i--) {
        if(it[i]==m) {
            st.push(arr[i].first);
            m--;
        }
    }
    for(i=0;i<n;i++){
        if(st.empty()||st.top()!=arr[i].first)cout<<arr[i].first<<'\n';
        else st.pop();
    }
    return 0;
}
