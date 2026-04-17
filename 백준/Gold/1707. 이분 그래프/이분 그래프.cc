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
ll t, v, e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>v>>e;
        vector<vector<ll>>arr(v+1);
        for(i=0;i<e;i++){
            ll a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        vector<ll> brr(v+1);
        bool ans=1;
        for(i=1;i<=v;i++){
            if(!brr[i]){
                brr[i]=1;
                queue<ll> que;
                que.push(i);
                while(!que.empty()){
                    ll now=que.front();
                    que.pop();
                    for(auto k:arr[now]){
                        if(brr[k]){
                            if(brr[k]==brr[now])ans=0;
                        }
                        else{
                            brr[k]=(brr[now]==1?2:1);
                            que.push(k);
                        }
                    }
                }
            }
        }
        ans?cout<<"YES\n":cout<<"NO\n";
    }

    return 0;
}
