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
    while(1){
        cin>>n;
        if(n==0)return 0;
        ll ans=0;
        stack<pll> st;
        st.push({0,-1});
        for(i=0;i<n;i++){
            ll t;
            cin>>t;
            if(i==0){
                st.push({t,0});
                continue;
            }
            ll k=i;
            while(st.top().first>t){
                ans=max(ans,st.top().first*(i-(k=st.top().second)));
                st.pop();
            }
            st.push({t,k});
        }
        while(!st.empty()){
            ans=max(ans,st.top().first*(i-st.top().second));
            st.pop();
        }
        cout<<ans<<'\n';
    }
    return 0;
}
