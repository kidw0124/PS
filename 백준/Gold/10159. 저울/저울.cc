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
ll n,m;
vector<vector<ll>>arr,brr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1);
    brr.resize(n+1);
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        brr[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        vector<bool>visit(n+1,0);
        vector<bool>vvisit(n+1,0);
        stack<ll> st;
        visit[i]=1;
        st.push(i);
        while(!st.empty()){
            ll now=st.top();
            st.pop();
            for(auto k:arr[now]){
                if(visit[k])continue;
                else {
                    visit[k]=1;
                    st.push(k);
                }
            }
        }
        vvisit[i]=1;
        st.push(i);
        while(!st.empty()){
            ll now=st.top();
            st.pop();
            for(auto k:brr[now]){
                if(vvisit[k])continue;
                else {
                    vvisit[k]=1;
                    st.push(k);
                }
            }
        }
        ll ans=0;
        for(j=1;j<=n;j++){
            if(!visit[j]&&!vvisit[j])ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}
