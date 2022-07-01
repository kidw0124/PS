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
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll a,b,c,d,sum;
ll t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        sum=a+2*b+3*c+4*d;
        if(a>2||(a>1&&c)||(a&&b)||(!b&&!c&&!d)){
            cout<<sum+1;
        }
        else{
            if(b){
                b+=d*2;
                d=0;
            }
            if(!d){
                if(!b&&!a){
                    cout<<c+1;
                }
                else if(b<2){
                    cout<<2*(c+1);
                }
                else if(c){
                    cout<<sum-1;
                }
                else{
                    cout<<b+1;
                }
            }
            else if(!b&&(c<3||(!a&&d==1))){
                cout<<(a+1+c)*(d+1)+a*c;
            }
            else{
                if(a){
                    cout<<sum-1;
                }
                else{
                    cout<<sum-5;
                }
            }
        }
        cout<<'\n';

    }

    return 0;
}
