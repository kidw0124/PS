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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<vector<ll>>arr(n,vector<ll>(n));
    ll a,b;
    cin>>a>>b;
    ll now=0;
    for(i=0;now<a;i++){
        for(j=0;j<=i&&now<a;j++){
            if(j>=n||i-j>=n||j<0||i-j<0)continue;
            if(arr[j][i-j]){
                cout<<-1;
                return 0;
            }
            arr[j][i-j]=1;
            now++;
        }
    }
    now=0;
    for(i=0;now<b;i++){
        for(j=0;j<=i&&now<b;j++){
            if(n-j-1<0||n-i+j-1<0||n-j-1>=n||n-i+j-1>=n)continue;
            if(arr[n-j-1][n-i+j-1]){
                cout<<-1;
                return 0;
            }
            arr[n-j-1][n-i+j-1]=2;
            now++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i+1<n){
                if(arr[i][j]+arr[i+1][j]==3){
                    cout<<-1;
                    return 0;
                }
            }
            if(j+1<n){
                if(arr[i][j]+arr[i][j+1]==3){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<"1\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
