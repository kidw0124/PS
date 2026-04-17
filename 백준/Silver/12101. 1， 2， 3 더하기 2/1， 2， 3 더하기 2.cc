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
ll n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>k;
    vector<ll>arr(21);
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(i=4;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    if(arr[n]<k){
        cout<<-1;
    }
    else{
        while(n){
            if(n>3){
                if(arr[n-1]>=k){
                    cout<<"1+";
                    n=n-1;
                }
                else if(arr[n-1]+arr[n-2]>=k){
                    cout<<"2+";
                    k-=arr[n-1];
                    n=n-2;
                }
                else{
                    cout<<"3+";
                    k-=arr[n-1]+arr[n-2];
                    n=n-3;
                }
            }
            else{
                if(n==3){
                    switch(k){
                    case 1:
                        cout<<"1+1+1";
                        break;
                    case 2:
                        cout<<"1+2";
                        break;
                    case 3:
                        cout<<"2+1";
                        break;
                    case 4:
                        cout<<"3";
                        break;
                    }
                }
                else if(n==2){
                    switch(k){
                    case 1:
                        cout<<"1+1";
                        break;
                    case 2:
                        cout<<"2";
                        break;
                    }
                }
                else{
                    cout<<"1";
                }
                n=0;
            }
        }
    }
    return 0;
}
