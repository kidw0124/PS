#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#else

    cin.tie(0)->sync_with_stdio(0);

#endif

    ll i,j;

    ll n;

    cin>>n;

    vector<ll>crr(n<<1);

    vector<ll>ans(n<<1|1);

    for(auto&x:crr)cin>>x;

    vector<vector<ll>>div;

    ll now=2*n;

    while(now>0){

        auto it=max_element(crr.begin(),crr.begin()+now);

        div.push_back(vector<ll>(it,crr.begin()+now));

        now=it-crr.begin();

    }

    ll m=div.size();

    div.push_back({});

    reverse(div.begin(), div.end());

    vector<ll>dp2(vector<ll>(n+1,-1));

    vector<ll>pre(vector<ll>(n+1,-1));

    dp2[0]=0;

    pre[0]=0;

    for(i=1;i<=m;i++){

        for(j=n;j>=0;j--){

            ll nj=j+div[i].size();

            if(nj<=n && dp2[j]!=-1 && dp2[nj]==-1){

                dp2[nj]=i;

                pre[nj]=j;

                if(nj==n){

                    while(nj>0){

                        for(auto k:div[dp2[nj]])ans[k]=1;

                        nj=pre[nj];

                    }

                    for(auto k:crr)if(ans[k])cout<<k<<' ';cout<<'\n';

                    for(auto k:crr)if(!ans[k])cout<<k<<' ';cout<<'\n';

                    return 0;

                }

            }

        }

    }

    cout<<-1;

}