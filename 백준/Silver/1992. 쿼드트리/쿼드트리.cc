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
ll n;
string arr[70];
void func(int a, int b, int s){
    ll p=arr[a][b],l=0;
    if(s==1){
        cout<<arr[a][b];
        return;
    }
    for(int i=a;i<s+a;i++){
        for(int j=b;j<b+s;j++){
            if(p!=arr[i][j])l=1;
        }
    }
    if(!l){
        cout<<arr[a][b];
        return;
    }
    else{
        cout<<"(";
        func(a,b,s/2);
        func(a,b+s/2,s/2);
        func(a+s/2,b,s/2);
        func(a+s/2,b+s/2,s/2);
        cout<<")";
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    func(0,0,n);

    return 0;
}
