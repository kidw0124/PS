#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

#ifdef ONLINEJUDGE
constexpr bool isdebug=false;
#else
constexpr bool isdebug=true;
#endif

#define debug if(isdebug)cout<<"[DEBUG] "
#define debugc(x) if(isdebug){cout<<"[DEBUG] "<<#x<<" : ";for(int j=0;j<x.size();j++)cout<<x[j]<<' ';cout<<"\n";}
#define debugv(x) if(isdebug){cout<<"[DEBUG] "<<#x<<" : ";cout<<x<<' ';cout<<"\n";}

void solve(){
    ll i,j,k;
    vector<vector<bool>>wall(21+1,vector<bool>(360))
                        ,circle(21+1,vector<bool>(360))
                        ,dp(21+1,vector<bool>(360));
    vector<vector<pll>>par(21+1,vector<pll>(360));
    ll n;
    cin>>n;
    for(j=0;j<n;j++){
        char a;
        ll b,c,d;
        cin>>a>>b>>c>>d;
        if(a=='C'){
            i=c;
            while(i!=d){
                circle[b][i++]=1;
                if(i==360)i=0;
            }
        }
        else{
            for(i=b;i<c;i++){
                wall[i][d]=1;
            }
        }
    }
    queue<pll>que;
    for(i=0;i<360;i++){
        dp[0][i]=1;
        que.push({0,i});
    }
//    debugc(wall[1])
//    debugc(wall[2])
    while(!que.empty()){
        auto [r,th]=que.front();
        que.pop();
//        debug<<r<<' '<<th<<'\n';
        if(!circle[r+1][th]){
            if(r==20){
                pll now={r,th};
                while(now.first!=0){
//                    debug<<now.first<<", "<<now.second<<'\n';
                    now=par[now.first][now.second];
                }
                cout<<"YES\n";
                return;
            }
            else if(!dp[r+1][th]){
                que.push({r+1,th});
                dp[r+1][th]=1;
                par[r+1][th]={r,th};
            }
        }
        if(r>1&&!circle[r][th]){
            if(!dp[r-1][th]){
                que.push({r-1,th});
                dp[r-1][th]=1;
                par[r-1][th]={r,th};
            }
        }
        if(r>0&&!wall[r][th]){
            if(!dp[r][(th+359)%360]){
                que.push({r,(th+359)%360});
                dp[r][(th+359)%360]=1;
                par[r][(th+359)%360]={r,th};
            }
        }
        if(r>0&&!wall[r][(th+1)%360]){
            if(!dp[r][(th+1)%360]){
                que.push({r,(th+1)%360});
                dp[r][(th+1)%360]=1;
                par[r][(th+1)%360]={r,th};
            }
        }
    }
    cout<<"NO\n";


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}