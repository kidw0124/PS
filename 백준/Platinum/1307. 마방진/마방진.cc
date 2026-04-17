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
vector<vector<ll>>odd(ll n){
    vector<vector<ll>>arr(n,vector<ll>(n));
    pll now={1,n/2+1};
    ll i;
    for(i=1;i<=n*n;i++){
        now={(now.first+n-1)%n,(now.second+n-1)%n};
        if(arr[now.first][now.second])now.first=(now.first+2)%n,now.second=(now.second+1)%n;
        arr[now.first][now.second]=i;
    }
    return arr;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n,vector<ll>(n));
    if(n&1){
        arr=odd(n);
    }
    else if(n%4==0){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                arr[i][j]=i*n+j+1;
            }
        }
        vector<vector<bool>>brr(n,vector<bool>(n));
        for(i=0;i<n/4;i++){
            for(j=0;j<n/4;j++){
                brr[i][j]=brr[i][n-j-1]=brr[n-i-1][j]=brr[n-i-1][n-j-1]=1;
                brr[n/4+i][n/4+j]=brr[n/4+i][n-j-1-n/4]=brr[n-i-1-n/4][n/4+j]=brr[n-i-1-n/4][n-j-1-n/4]=1;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n/2;j++){
                if(!brr[i][j])swap(arr[i][j],arr[n-i-1][n-j-1]);
            }
        }
    }
    else{
        ll s=n*n/4;
        auto x=odd(n/2);
        for(i=0;i<n/2;i++){
            for(j=0;j<n/4;j++){
                arr[i][j]=3*s;
            }
        }
        arr[n/4][0]=0;
        arr[n/4][n/4]=3*s;
        for(i=n/2;i<n;i++){
            for(j=n/4;j<n/2;j++){
                arr[i][j]=3*s;
            }
        }
        arr[n/4+n/2][0]=3*s;
        arr[n/4+n/2][n/4]=0;
        for(i=0;i<n/2;i++){
            for(j=n/2;j<n-n/4+1;j++){
                arr[i][j]=2*s;
            }
            for(;j<n;j++){
                arr[i][j]=s;
            }
        }
        for(i=n/2;i<n;i++){
            for(j=n/2;j<n-n/4+1;j++){
                arr[i][j]=s;
            }
            for(;j<n;j++){
                arr[i][j]=2*s;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                arr[i][j]+=x[i%(n/2)][j%(n/2)];
            }
        }
    }

    for(auto k:arr){
        for(auto kk:k)cout<<kk<<' ';
        cout<<'\n';
    }
    set<ll>st;
    return 0;
}
