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

map<tuple<ll,ll,ll>,ll> arr;

ll func(ll a, ll b, ll c){
    if(arr.find({a,b,c})==arr.end()){
        if(a<=0||b<=0||c<=0){
            return 1;
        }
        else if(a>20||b>20||c>20){
            return func(20,20,20);
        }
        else if(a<b&&b<c){
            return arr[{a,b,c}]=func(a,b,c-1)+func(a, b-1, c-1)-func(a, b-1, c);
        }
        else{
            return arr[{a,b,c}]= func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) - func(a-1, b-1, c-1);
        }
    }
    else return arr[{a,b,c}];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll a,b,c=0;
    cin>>a>>b>>c;
    while(make_tuple(a,b,c)!=make_tuple(-1,-1,-1)){
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<func(a,b,c)<<'\n';
        cin>>a>>b>>c;
    }

    return 0;
}
