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
ll n;
ll ans=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>j;
    while(j--){
        string str;
        cin>>str;
        ll now=0;
        n=str.size();
        for(i=0;i<n-2;i++){
            if(str[i]=='f'){
                if(str[i+1]=='o'){
                    i++;
                    if(str[i+1]=='r'){
                        i++;
                        now++;
                    }
                }
            }
            if(i<n-4&&str[i]=='w'){
                if(str[i+1]=='h'){
                    i++;
                    if(str[i+1]=='i'){
                        i++;
                        if(str[i+1]=='l'){
                            i++;
                            if(str[i+1]=='e'){
                                i++;
                                now++;
                            }
                        }
                    }
                }
            }
        }
            ans=max(ans,now);
    }
    cout<<ans;
    return 0;
}
