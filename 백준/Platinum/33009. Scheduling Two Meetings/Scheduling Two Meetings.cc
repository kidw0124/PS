#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

void solve(ll tc){
    int i,j;
    int n,m;
    cin>>n>>m;
    vector<string>arr(n);
    vector<int>brr(n),rbrr(1<<m,n);
    vector<pii>dp(1<<m,{-1,-n});
    for(i=0;i<n;i++){
        cin>>arr[i];
        int tmp=0;
        for(j=0;j<m;j++){
            if(arr[i][j]=='Y')brr[i]|=1<<j;
            else tmp|=1<<j;
        }
        rbrr[brr[i]]=min(rbrr[brr[i]],i);
        dp[tmp]=max(dp[tmp],{0,-i});
    }
    pair<int,pii>ans={-1,{-n,-n}};
    for(i=0;i<(1<<m);i++){
        if(dp[i].first!=-1){
            for(j=0;j<m;j++){
                if(!(i&(1<<j))){
                    int ni=i|(1<<j);
                    dp[ni]=max(dp[ni],{dp[i].first+1,dp[i].second});
                }
            }
        }
    }
    for(i=0;i<(1<<m)-1;i++){
        if(dp[i].first!=-1&&rbrr[i]!=n){
            pii tmp=minmax(-dp[i].second,rbrr[i]);
            tmp={-tmp.first,-tmp.second};
            ans=max(ans,{dp[i].first,tmp});
        }
    }
    auto it=find(brr.begin(), brr.end(),(1<<m)-1);
    if(find(brr.begin(), brr.end(),(1<<m)-1)!=brr.end()){
        int mm=it-brr.begin();
        for(i=0;i<n;i++){
            if(i!=mm){
                int pc=__builtin_popcount(brr[i]);
                pii tmp=minmax(i,mm);
                tmp={-tmp.first,-tmp.second};

                ans=max(ans,{pc,tmp});

            }
        }
    }
    if(ans.first==-1)cout<<"No";
    else cout<<-ans.second.first+1<<" "<<-ans.second.second+1;


}

void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
#endif
}
void preprocess(){
    ll i,j;
}
int main(){
    setup();
    ll t=1;
//    cin>>t;
    for(ll tc=0;tc<t;tc++){
        solve(tc+1);
    }
}
