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

struct building{
    int num;
    int time;
    int tot;
    bool visit=false;
    set<ll>par;
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<building>arr(n+1);
        for(i=1;i<=n;i++){
            arr[i].num=i;
            cin>>arr[i].time;
            arr[i].tot=arr[i].time;
        }
        for(i=0;i<k;i++){
            ll a,b;
            cin>>a>>b;
            arr[b].par.insert(a);
        }
        ll w;
        cin>>w;
        queue<int>que;
        while(1){
            for(i=1;i<=n;i++){
                if(arr[i].par.empty()&&!arr[i].visit){
                    que.push(i);
                    arr[i].visit=true;
                }
            }
            int x=que.front();
            que.pop();
            if(x==w){
                cout<<arr[x].tot<<'\n';
                break;
            }
            else{
                for(i=1;i<=n;i++){
                    if(arr[i].par.find(x)!=arr[i].par.end()&&!arr[i].visit){
                        arr[i].par.erase(arr[i].par.find(x));
                        arr[i].tot=max(arr[x].tot+arr[i].time,arr[i].tot);
                    }
                }
            }
        }
    }


    return 0;
}
