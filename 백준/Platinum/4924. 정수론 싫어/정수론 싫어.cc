#include <bits/stdc++.h>
using namespace std;

void solve() {
    int i,j,cnt=0;
    vector<int> spf(1'000'000+1);
    for(i=2;i<=1'000'000;++i) {
        if(spf[i]==0) {
            for(j=i;j<=1'000'000;j+=i) {
                if(spf[j]==0) spf[j]=i;
            }
        }
    }
    vector<int> primes(1e6+1);
    primes[1]=0;
    for(i=2;i<=1'000'000;++i) {
        primes[i]=primes[i/spf[i]]+1;
    }
    for(i=1;i<=1'000'000;++i) {
        if(primes[i]==1)primes[i]=-2;
        else primes[i]--;
    }
    while(cin>>i>>j, i!=-1&&j!=-1) {
        cout<< ++cnt <<". ";
        int ans=primes[i],now=0;
        for(int k=i;k<=j;++k) {
            now=max(0,now)+primes[k];
            ans=max(ans,now);
        }
        cout<<ans<<'\n';
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}