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
string a,b,c;
vector<vector<vector<ll>>>arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>a>>b>>c;
    arr.resize(a.size()+1,vector<vector<ll>>(b.size()+1,vector<ll>(c.size()+1)));
    for(i=1;i<=a.size();i++){
        for(j=1;j<=b.size();j++){
            for(ll k=1;k<=c.size();k++){
                arr[i][j][k]=max({arr[i][j][k-1],arr[i][j-1][k],arr[i-1][j][k]});
                if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]){
                    arr[i][j][k]=max(arr[i][j][k],arr[i-1][j-1][k-1]+1);
                }
            }
        }
    }
    cout<<arr[a.size()][b.size()][c.size()];
    return 0;
}
