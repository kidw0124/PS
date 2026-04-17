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
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,m;
vector<vector<int>>divs;
vector<ll>answers;
const ll mimim=1e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<int>arr(n+1);
    vector<ll>sum(n+1);
    vector<pll>xsum;
    answers.resize(n+1,-mimim);
    divs.resize(n+1);
    for(i=1;i<=n;i++)cin>>arr[i];
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i){
            sum[i]+=arr[j];
            divs[j].push_back(i);
        }
        xsum.push_back({sum[i],i});
    }
    sort(all(xsum),greater<pll>());
    cin>>m;
    ll a=0;
    for(j=0;j<m;j++){
        ll p,s;
        cin>>p>>s;
        i=0;
        if(n==1){
            a+=arr[1]+s;
            continue;
        }
        else if(n==2&&p==2){
            a+=min(arr[1]+arr[2]+s,arr[2]+s);
        }
        else{
            while(i<n-1&&p%xsum[i].second==0)i++;
            if(answers[p]==-mimim){
				for(int k:divs[p]){
					answers[p]=max(sum[k],answers[p]);
				}
            }
			a+=max(answers[p]+s,xsum[i].first);
        }
    }
    cout<<a;

    return 0;
}
