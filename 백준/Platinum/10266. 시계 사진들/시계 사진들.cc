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
ll n;
vector<ll>arr,brr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(n),brr.resize(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        cin>>brr[i];
    }
    sort(all(arr));
    sort(all(brr));
    arr.push_back(arr[0]+360'000);
    brr.push_back(brr[0]+360'000);

    vector<ll>crr(n),drr(n);
    for(i=0;i<n;i++){
        crr[i]=arr[i+1]-arr[i];
        drr[i]=brr[i+1]-brr[i];
    }
//    for(auto k:crr){
//        cout<<k<<' ';
//    }
//    cout<<'\n';
//    for(auto k:drr){
//        cout<<k<<' ';
//    }
//    cout<<'\n';
    string sarr="";
    string sbrr="",scrr="";
    char x='a';
    for(i=0;i<2*n;i++){
        for(j=0;j<crr[i%n];j++){
            sarr+=x;
        }
        x=(x=='a'?'b':'a');
    }
    x='a';
    for(i=0;i<n;i++){
        for(j=0;j<drr[i%n];j++){
            sbrr+=x;
        }
        x=(x=='a'?'b':'a');
    }
    x='b';
    for(i=0;i<n;i++){
        for(j=0;j<drr[i%n];j++){
            scrr+=x;
        }
        x=(x=='a'?'b':'a');
    }
//    cout<<sarr<<'\n';
//    cout<<sbrr<<'\n';
//    cout<<scrr<<'\n';
    vector<int>kmp(sbrr.size(),0);
    j=0;
    for(i=1;i<sbrr.size();i++) {
		while(j>0&&sbrr[i]!=sbrr[j])
			j=kmp[j-1];
		if(sbrr[i]==sbrr[j])
            kmp[i]=++j;
	}
    j=0;
    for(i=0;i<sarr.size();i++){
        while(j>0&&sarr[i]!=sbrr[j]){
            j=kmp[j-1];
        }
        if(sarr[i]==sbrr[j]){
            j++;
            if(j==sbrr.size()){
                cout<<"possible";
                //cout<<i-n+2;
                return 0;
            }
        }
    }
    kmp.clear();
    kmp.resize(scrr.size(),0);
    j=0;
    for(i=1;i<scrr.size();i++) {
		while(j>0&&scrr[i]!=scrr[j])
			j=kmp[j-1];
		if(scrr[i]==scrr[j])
            kmp[i]=++j;
	}
    j=0;
    for(i=0;i<sarr.size();i++){
        while(j>0&&sarr[i]!=scrr[j]){
            j=kmp[j-1];
        }
        if(sarr[i]==scrr[j]){
            j++;
            if(j==scrr.size()){
                cout<<"possible";
                return 0;
            }
        }
    }
    cout<<"impossible";
    return 0;
}
