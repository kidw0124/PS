#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#ifdef DWOO
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
void setup(){
#ifdef DWOO
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
}
void preprocess(){

}

void solve(ll testcase){
    ll n,i,j;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end(),greater<>());
    ll a=0,b=0;
    for(i=0;i<min(42ll,n);i++){
        a+=arr[i];
        if(arr[i]>=250)b+=5;
        else if(arr[i]>=200)b+=4;
        else if(arr[i]>=140)b+=3;
        else if(arr[i]>=100)b+=2;
        else if(arr[i]>=60)b+=1;
    }
    cout<<a<<' '<<b;
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll testcase = 1; testcase<=t;testcase++)solve(testcase);
}