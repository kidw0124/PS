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
ll b,p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    while(1){
        cin>>b>>p;
        b=-b;
        vl arr(b),time(b),brr(b),crr(b),drr(b);
        if(b||p){
            for(i=0;i<b;i++){
                cin>>arr[i]>>time[i];;
            }
            brr[0]=p;
            ll tot=0;
            while(p){
                for(i=0;i<b;i++){
                    if(brr[i]&&!crr[i]){
                        ll pp=min(brr[i],arr[i]);
                        brr[i]-=pp;
                        drr[i]=pp;
                        crr[i]=time[i];
                    }
                }
                tot++;
                for(i=0;i<b;i++){
                    if(i==b-1&&crr[i]==1){p-=drr[i];drr[i]=0;}
                    else if(crr[i]==1){brr[i+1]+=drr[i];drr[i]=0;}
                    if(crr[i])crr[i]--;
                }
            }
            cout<<tot<<'\n';
        }
        else return 0;
    }

    return 0;
}
