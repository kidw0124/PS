#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int i,j,k;
    bitset<2'000'000>bs;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        int now=arr[i];
        while(bs[now]){
            bs[now]=0;
            now++;
        }
        bs[now]=1;
    }
    if(bs.count()>2){
        cout<<'N';
    }
    else if(bs.count()==2){
        cout<<'Y';
    }
    else if(n==1){
        cout<<'N';
    }
    else cout<<'Y';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    solve();
}