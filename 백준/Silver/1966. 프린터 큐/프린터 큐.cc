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
ll t,n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>n>>m;
        deque<pair<ll,ll>>que(n);
        for(i=0;i<n;i++){
            cin>>que[i].first;
            que[i].second=i;
        }
        int ans=0;
        while(1){
            for(i=1;i<que.size();i++){
                if(que[0].first<que[i].first){
                    que.push_back(que[0]);
                    que.pop_front();
                    break;
                }
            }
            if(i==que.size()){
                ans++;
                //cout<<que[0].second;
                if(que[0].second==m){
                    cout<<ans<<'\n';
                    que.clear();
                    break;
                }
                else{
                    que.pop_front();
                }
            }
        }
    }


    return 0;
}
