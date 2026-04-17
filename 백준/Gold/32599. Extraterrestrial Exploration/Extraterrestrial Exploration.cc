#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    ll st=2,en=n-1,now=INT_MAX,ans=n-1;
    vector<ll>arr(n+1);
    cout<<"? 1"<<endl;
    cin>>arr[1];
    cout<<"? "<<n<<endl;
    cin>>arr[n];
    auto f=[](ll a, ll b, ll c)->ll{
        return (2*b-c-a);
    };
    while(st<=en){
        ll mid=(st+en)>>1;
        cout<<"? "<<mid<<endl;
        cin>>arr[mid];
        ll ff=f(arr[1],arr[mid],arr[n]);
        if(abs(ff)<now){
            now=abs(ff),ans=mid;
        }
        if(ff<0){
            st=mid+1;
        }
        else if(ff==0){
            break;
        }
        else{
            en=mid-1;
        }
    }
    cout<<"! 1 "<<ans<<" "<<n<<endl;
}

int main() {
#ifdef ONLINE_JUDGE
    //    cin.tie(0)->sync_with_stdio(0);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}