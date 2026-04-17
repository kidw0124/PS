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

struct lang{
    string minsik;
    string minsik_conv(){
        string temp;
        for(ll i=0;i<minsik.size();i++){
            if((i-minsik.size()+1)&&minsik[i]=='n'&&minsik[i+1]=='g')temp+='o',i++;
            else if(minsik[i]=='k')temp+='c';
            else if(minsik[i]>'n')temp+=minsik[i]+1;
            else temp+=minsik[i];
        }
        return temp;
    }
    bool operator<(lang r){
        return minsik_conv()<r.minsik_conv();
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<lang>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].minsik;
    }
    sort(arr.begin(),arr.end());

    for(i=0;i<n;i++){
        cout<<arr[i].minsik<<'\n';
    }

    return 0;
}
