#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"0 0"<<endl;
        cout<<flush;
        ll d;
        cin>>d;
        if(d==0)continue;
        for(j=0;j*j<=d;j++){
            ll k=d-j*j;
            k=(ll)sqrt(k);
            if(j>1e6||k>1e6)continue;
            if(j*j+k*k==d){
                cout<<j<<" "<<k<<endl;
                cout<<flush;
                ll p;
                cin>>p;
                if(p==0)break;
            }
        }
    }
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