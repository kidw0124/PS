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
ll n,k;
ll ori[4];
ll idx[4];
vector<ll>arr[4];
deque<ll>prefix[4];
bool cmp(pll a, pll b){
    return a.second*b.first<a.first*b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>k;
    for(i=0;i<4;i++){
        cin>>ori[i];
    }
    for(i=0;i<n;i++){
        char x;
        ll y;
        cin>>x>>y;
        x-='A';
        arr[x].push_back(y);
    }
    for(i=0;i<4;i++){
        sort(arr[i].begin(),arr[i].end(),greater<ll>());
        prefix[i].pb(ori[i]);
        for(j=0;j<arr[i].size();j++){
            prefix[i].pb(prefix[i][j]+arr[i][j]);
        }
    }
    for(i=0;i<k;i++){
        vector<pll> vct;
        for(j=0;j<4;j++){
            if(idx[j]<arr[j].size()){
                vct.push_back({prefix[j][idx[j]],prefix[j][idx[j]+1]});
            }
        }
        sort(vct.begin(),vct.end(),cmp);
        reverse(vct.begin(),vct.end());
        for(j=0;j<4;j++){
            if(idx[j]<arr[j].size()){
                if(prefix[j][idx[j]]==vct[0].first&&prefix[j][idx[j]+1]==vct[0].second){
                    cout<<(char)(j+'A')<<' '<<arr[j][idx[j]++]<<'\n';
                    break;
                }
            }
        }
        vct.clear();
    }


    return 0;
}
