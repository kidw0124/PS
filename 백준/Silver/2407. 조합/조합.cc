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
string arr[105][105];

string str_plus(string a, string b){
    string res;
    ll carry=0;
    while((!a.empty()) || (!b.empty()) || carry){
        if(!a.empty()){
            carry+=a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            carry+=b.back()-'0';
            b.pop_back();
        }
        res=(char)('0'+carry%10)+res;
        carry/=10;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,n,m;
    for(i=0;i<=100;i++){
        for(j=0;j<=i;j++){
            if(i==j||j==0)arr[i][j]="1";
            else arr[i][j]=str_plus(arr[i-1][j],arr[i-1][j-1]);
        }
    }
    cin>>n>>m;
    cout<<arr[n][m];
    return 0;
}
