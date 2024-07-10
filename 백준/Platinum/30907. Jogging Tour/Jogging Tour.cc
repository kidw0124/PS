#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;

void solve() {
    ll i,j,k,l;
    ll n;
    cin>>n;
    vector<pld>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    auto get_theta=[](pld a, pld b)->ld{
        if(a.first-b.first==0){
            return acos((ld)-1)/2;
        }
        ld ret=atan((a.second-b.second)/(a.first-b.first));
        return ret;
    };
    auto cps=[](ld theta)->ld{
        return abs(cos(theta))+abs(sin(theta));
    };
    auto cms=[](ld theta)->ld{
        return abs(abs(cos(theta))-abs(sin(theta)));
    };
    auto dist=[&cps,&cms](ld alpha, ld theta)->ld{
        ld ccc=cps(abs(alpha-theta));
//        cout<<theta<<' '<<alpha<<' ';
//        cout<<ccc<<'\n';
        if(alpha*theta>=0)return cps(abs(alpha-theta));
        else return cps(acos((ld)-1)/2-abs(abs(alpha)+abs(theta)-acos((ld)-1)));
    };
    auto dist_euclid=[](pld a, pld b)->ld{
        return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
    };
    auto dist_dd=[](pld a, pld b)->ld{
        return abs(a.first-b.first)+abs(a.second-b.second);
    };
    ld ans=1e18;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            vector<pld>crr=arr;
            vector<vector<ld>>brr(n+1,vector<ld>(n+1));
            ld bitbyeon=dist_euclid(crr[i],crr[j]);
            ld ct=(crr[j].first-crr[i].first)/bitbyeon;
            ld st=-(crr[j].second-crr[i].second)/bitbyeon;
            auto rotate=[&ct,&st](pld a)->pld{
                return {a.first*ct-a.second*st,a.first*st+a.second*ct};
            };
            for(auto &c:crr)c=rotate(c);
            for(k=0;k<n;k++){
                for(l=k+1;l<n;l++){
//                        cout<<k<<' '<<l<<' ';
                    brr[k][l]=brr[l][k]=dist_dd(crr[k],crr[l]);
                }
            }
            vector<vector<ld>>ans_dist(n+1,vector<ld>(2<<n,1e18));
            vector<vector<pll>>pre(n+1,vector<pll>(2<<n));
            ans_dist[n][0]=0;
            for(k=0;k<(2<<n)-1;k++){
                for(l=0;l<=n;l++){
                    for(ll m=0;m<=n;m++){
                        if(!(k&(1<<m))){
                            if(ans_dist[m][k|(1<<m)]>ans_dist[l][k]+brr[l][m]){
                                ans_dist[m][k|(1<<m)]=ans_dist[l][k]+brr[l][m];
                                pre[m][k|(1<<m)]={l,k};
                            }
                        }
                    }
                }
            }
            for(k=0;k<n;k++){
                ans=min(ans,ans_dist[n].back());
            }
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<'\n';
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
}