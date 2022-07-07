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

vector<ll>grundy;
vector<ll>arr;
ll mex(set<ll>&arr){
    ll i=0;
    for(auto k:arr){
        if(k!=i)return i;
        else i++;
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
//    grundy.resize((ll)5e6);
//    grundy[0]=0;
//    grundy[1]=1;
    arr={0,4,8,14,20,24,28,34,38,42,54,58,62};
    while(arr.back()<5e6){
        arr.push_back(34+*(arr.end()-5));
    }
//    for(i=2;i<10000;i++){
//        set<ll>x;
//        if(i>=2)x.insert(grundy[i-2]);
//        for(j=0;j<=(i-3)/2;j++){
//            x.insert(grundy[j]^grundy[i-3-j]);
//        }
//        grundy[i]=mex(x);
//    }
//    ll p=0;
//    for(i=0;i<8000;i++){
////        cout<<i<<' '<<grundy[i]<<'\n';
//        if(!grundy[i]){
//            if(i){
//                cout<<"---------"<<i-p<<'\n';
//                p=i;
//            }
//            cout<<i<<'\n';
//        }
//    }
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<(!binary_search(all(arr),n)?"Yuto\n":"Platina\n");
    }

    return 0;
}
